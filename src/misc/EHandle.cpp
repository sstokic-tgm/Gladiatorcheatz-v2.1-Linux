#include "EHandle.h"

// -------------------------------------------------------------------------------------------------- //
// Game-code CBaseHandle implementation.
// -------------------------------------------------------------------------------------------------- //

IHandleEntity* CBaseHandle::Get() const
{
    return g_EntityList->GetClientEntityFromHandle(*this);
}
