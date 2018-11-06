#pragma once

#include "interface.h"
#include "dt_recv.h"
#include "../interfaces/IClientNetworkable.h"

class ClientClass;

using CreateClientClassFn = IClientNetworkable*(*)(int entnum, int serialNum);
using CreateEventFn = IClientNetworkable*(*)();

class ClientClass
{
public:
	CreateClientClassFn m_pCreateFn;
	CreateEventFn m_pCreateEventFn;
	char *m_pNetworkName;
	RecvTable *m_pRecvTable;
	ClientClass *m_pNext;
	int m_ClassID;
};
