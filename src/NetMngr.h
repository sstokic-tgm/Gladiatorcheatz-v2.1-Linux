#pragma once

#include <unordered_map>

#include "misc/dt_recv.h"
#include "Singleton.h"

class NetMngr : public Singleton<NetMngr>
{
public:
    void init();
    int getOffs(const char *tableName, const char *propName);
    bool hookProp(const char *tableName, const char *propName, RecvVarProxyFn func);
    bool hookProp(const char *tableName, const char *propName, RecvVarProxyFn func, RecvVarProxyFn &orig);

    void dump();

private:
    std::unordered_map<std::string, RecvTable*> tables;

    int getProp(const char *tableName, const char *propName, RecvProp **prop = 0);
    int getProp(RecvTable *recvTable, const char *propName, RecvProp **prop = 0);
    RecvTable *getTable(const char *tableName);

    std::string dumpTable(RecvTable *recvTable, std::string tabs);
    std::string type2str(Type t);
};
