#pragma once

#include "common.h"

#include "misc/interface.h"
#include "misc/Enums.h"
#include "vfunc.h"

#include "math/VMatrix.h"
#include "math/QAngle.h"
#include "math/Vector.h"
#include "misc/Studio.h"

#include "misc/client_class.h"
#include "interfaces/IAppSystem.h"
#include "interfaces/cdll_int.h"
#include "interfaces/IClientEntity.h"
#include "interfaces/IClientEntityList.h"
#include "interfaces/IClientMode.h"
#include "interfaces/IConVar.h"
#include "interfaces/ICvar.h"
#include "interfaces/IEngineTrace.h"
#include "interfaces/IVDebugOverlay.h"
#include "interfaces/ISurface.h"
#include "interfaces/CInput.h"
#include "interfaces/IVModelInfoClient.h"
#include "interfaces/IVModelRender.h"
#include "interfaces/IRenderView.h"
#include "interfaces/IGameEventmanager.h"
#include "interfaces/IMaterialSystem.h"
#include "interfaces/IMoveHelper.h"
#include "interfaces/IMDLCache.h"
#include "interfaces/IPrediction.h"
#include "interfaces/IPanel.h"
#include "interfaces/IEngineSound.h"
#include "interfaces/IViewRender.h"
#include "interfaces/CClientState.h"
#include "interfaces/IPhysics.h"
#include "interfaces/IInputSystem.h"
#include "interfaces/memalloc.h"
#include "interfaces/IViewRenderBeams.h"
#include "interfaces/ILocalize.h"

#include "misc/Convar.h"
#include "misc/CUserCmd.h"
#include "misc/glow_outline_effect.h"
#include "misc/datamap.h"
#include "misc/EHandle.h"

#include "NetMngr.h"

extern IVEngineClient			*g_EngineClient;
extern IBaseClientDLL			*g_CHLClient;
extern IClientEntityList		*g_EntityList;
extern CGlobalVarsBase			*g_GlobalVars;
extern IEngineTrace				*g_EngineTrace;
extern ICvar					*g_CVar;
extern IPanel					*g_VGuiPanel;
extern IClientMode				*g_ClientMode;
extern IVDebugOverlay			*g_DebugOverlay;
extern ISurface					*g_VGuiSurface;
extern CInput					*g_Input;
extern IVModelInfoClient		*g_MdlInfo;
extern IVModelRender			*g_MdlRender;
extern IVRenderView				*g_RenderView;
extern IMaterialSystem			*g_MatSystem;
extern IGameEventManager2		*g_GameEvents;
extern IMoveHelper				*g_MoveHelper;
extern IMDLCache				*g_MdlCache;
extern IPrediction				*g_Prediction;
extern CGameMovement			*g_GameMovement;
extern IEngineSound				*g_EngineSound;
extern CGlowObjectManager		*g_GlowObjManager;
extern CClientState				*g_ClientState;
extern IPhysicsSurfaceProps		*g_PhysSurface;
extern IInputSystem			    *g_InputSystem;
extern uintptr_t				*g_InputInternal;
extern IMemAlloc				*g_pMemAlloc;
extern IViewRenderBeams			*g_RenderBeams;
extern ILocalize                *g_Localize;
