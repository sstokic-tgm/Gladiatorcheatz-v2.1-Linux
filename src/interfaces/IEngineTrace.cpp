#include "../SDK.h"
#include "IEngineTrace.h"

bool CGameTrace::DidHitWorld() const
{
	return hit_entity == g_EntityList->GetClientEntity(0);
}

bool CGameTrace::DidHitNonWorldEntity() const
{
	return hit_entity != nullptr && !DidHitWorld();
}
