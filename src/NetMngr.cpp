#include "NetMngr.h"
#include "SDK.h"

void NetMngr::init()
{
    tables.clear();

    ClientClass *client = g_CHLClient->GetAllClasses();
    if(!client) return;

    while(client)
    {
        auto recvTable = client->m_pRecvTable;

        if(recvTable)
            tables.emplace(std::string(client->m_pNetworkName), recvTable);

        client = client->m_pNext;
    }
}

int NetMngr::getOffs(const char *tableName, const char *propName)
{
	int offs = this->getProp(tableName, propName);

	if (!offs)
		return 0;

	return offs;
}

bool NetMngr::hookProp(const char *tableName, const char *propName, RecvVarProxyFn func)
{
	RecvProp *prop = nullptr;

	this->getProp(tableName, propName, &prop);

	if (!prop)
		return false;

	prop->m_ProxyFn = func;

	return true;
}

bool NetMngr::hookProp(const char *tableName, const char *propName, RecvVarProxyFn func, RecvVarProxyFn &orig)
{
	RecvProp *prop = nullptr;

	this->getProp(tableName, propName, &prop);

	if (!prop)
		return false;

	orig = reinterpret_cast<RecvVarProxyFn>(prop->m_ProxyFn);

	prop->m_ProxyFn = func;

	return true;
}

int NetMngr::getProp(const char *tableName, const char *propName, RecvProp **prop)
{
	RecvTable *recvTable = this->getTable(tableName);

	if (!recvTable)
		return 0;

	int offs = this->getProp(recvTable, propName, prop);

	if (!offs)
		return 0;

	return offs;
}

int NetMngr::getProp(RecvTable *recvTable, const char *propName, RecvProp **prop)
{
	int extrOffs = 0;

	for (int i = 0; i < recvTable->m_nProps; i++)
	{
		auto *recvProp = &recvTable->m_pProps[i];
		auto recvChild = recvProp->m_pDataTable;

		if (recvChild && (recvChild->m_nProps > 0))
		{
			int tmp = this->getProp(recvChild, propName, prop);

			if (tmp)
				extrOffs += (recvProp->m_Offset + tmp);
		}

		if (strcmp(recvProp->m_pVarName, propName))
			continue;

		if (prop)
			*prop = recvProp;

		return (recvProp->m_Offset + extrOffs);
	}
	return extrOffs;
}

RecvTable *NetMngr::getTable(const char *tableName)
{
	if (tables.empty())
		return 0;

	for (auto table : tables)
	{
		if (strcmp(table.first.c_str(), tableName) == 0)
			return table.second;
	}

	return 0;
}

void NetMngr::dump()
{
    std::stringstream ss;

	for (ClientClass *client = g_CHLClient->GetAllClasses(); client != NULL; client = client->m_pNext)
	{
		auto table = client->m_pRecvTable;
        ss << client->m_pNetworkName << "\n";
		ss << this->dumpTable(table, "\t");
	}

    std::string netvarsPath = "/tmp/netvars.txt";
    std::ofstream(netvarsPath) << ss.str();
}

std::string NetMngr::dumpTable(RecvTable *table, std::string tabs)
{
    std::stringstream ss;

	for (int i = 0; i < table->m_nProps; i++)
	{
		auto recvProp = &table->m_pProps[i];

		if (recvProp->m_RecvType == Type::DPT_Array)
			continue;

        ss << tabs.c_str() << "\t" << "Name: " << recvProp->m_pVarName << " Offset: 0x" << std::hex << recvProp->m_Offset << " Type: " << this->type2str(recvProp->m_RecvType).c_str() << "\n";

		if (recvProp->m_RecvType == Type::DPT_DataTable)
		{
			ss << this->dumpTable(recvProp->m_pDataTable, tabs + "\t");
		}
	}

    return ss.str();
}

std::string NetMngr::type2str(Type t)
{
	switch (t)
	{
	case DPT_Int:
		return "Int";
	case DPT_Float:
		return "Float";
	case DPT_Vector:
		return "Vector";
	case DPT_VectorXY:
		return "VectorXY";
	case DPT_String:
		return "String";
	case DPT_Array:
		return "Array";
	case DPT_DataTable:
		return "DataTable";
	case DPT_Int64:
		return "Int64";
	case DPT_NUMSendPropTypes:
		return "NUMSendPropTypes";
	default:
		return "Unknown Type";
	}
}
