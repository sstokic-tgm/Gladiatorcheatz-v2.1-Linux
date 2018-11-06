#include "Install.h"
#include "Gamehooking.h"

IVEngineClient			*g_EngineClient = nullptr;
IBaseClientDLL			*g_CHLClient = nullptr;
IClientEntityList		*g_EntityList = nullptr;
CGlobalVarsBase			*g_GlobalVars = nullptr;
IEngineTrace			*g_EngineTrace = nullptr;
ICvar					*g_CVar = nullptr;
IPanel					*g_VGuiPanel = nullptr;
IClientMode				*g_ClientMode = nullptr;
IVDebugOverlay			*g_DebugOverlay = nullptr;
ISurface				*g_VGuiSurface = nullptr;
CInput					*g_Input = nullptr;
IVModelInfoClient		*g_MdlInfo = nullptr;
IVModelRender			*g_MdlRender = nullptr;
IVRenderView			*g_RenderView = nullptr;
IMaterialSystem			*g_MatSystem = nullptr;
IGameEventManager2		*g_GameEvents = nullptr;
IMoveHelper				*g_MoveHelper = nullptr;
IMDLCache				*g_MdlCache = nullptr;
IPrediction				*g_Prediction = nullptr;
CGameMovement			*g_GameMovement = nullptr;
IEngineSound			*g_EngineSound = nullptr;
CGlowObjectManager		*g_GlowObjManager = nullptr;
CClientState			*g_ClientState = nullptr;
IPhysicsSurfaceProps	*g_PhysSurface = nullptr;
IInputSystem			*g_InputSystem = nullptr;
uintptr_t				*g_InputInternal = nullptr;
IMemAlloc				*g_pMemAlloc = nullptr;
IViewRenderBeams	    *g_RenderBeams = nullptr;
ILocalize               *g_Localize = nullptr;

void Installer::installGladiator()
{

}

void Installer::uninstallGladiator()
{

}
