#pragma once

#include "SDK.h"
#include "Structs.h"
#include "helpers/VMTManager.h"

typedef bool(*CreateMove_t)(IClientMode*, float, CUserCmd*);
extern CreateMove_t o_CreateMove;

typedef void(*PaintTraverse_t)(void*, unsigned int, bool, bool);
extern PaintTraverse_t o_PaintTraverse;


namespace Hooks
{
    void PaintTraverse(void* thisptr, unsigned int panel, bool forceRepaint, bool allowForce);
    bool CreateMove(float smt, CUserCmd* userCMD);
}