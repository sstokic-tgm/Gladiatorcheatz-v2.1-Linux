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
C_BasePlayer            *g_LocalPlayer = nullptr;

namespace Offsets
{
    uintptr_t invalidateBoneCache = 0x00;
    uintptr_t smokeCount = 0x00;
    uintptr_t playerResource = 0x00;
    uintptr_t bOverridePostProcessingDisable = 0x00;
    uintptr_t getSequenceActivity = 0x00;
    uintptr_t lgtSmoke = 0x00;
    uintptr_t reevauluate_anim_lod = 0x00;
}

std::unique_ptr<ShadowVTManager> g_pVguiPanelHook = nullptr;
std::unique_ptr<ShadowVTManager> g_pClientModeHook = nullptr;

PaintTraverse_t o_PaintTraverse = nullptr;
CreateMove_t o_CreateMove = nullptr;

void Installer::installGladiator()
{
    g_EngineClient = IfaceMngr::Get().getIface<IVEngineClient>("./bin/linux64/engine_client.so", "VEngineClient");
    g_CHLClient = IfaceMngr::Get().getIface<IBaseClientDLL>("./csgo/bin/linux64/client_panorama_client.so", "VClient0");
    g_EntityList = IfaceMngr::Get().getIface<IClientEntityList>("./csgo/bin/linux64/client_panorama_client.so", "VClientEntityList");
    g_EngineTrace = IfaceMngr::Get().getIface<IEngineTrace>("./bin/linux64/engine_client.so", "EngineTraceClient");
    g_CVar = IfaceMngr::Get().getIface<ICvar>("./bin/linux64/materialsystem_client.so", "VEngineCvar");
    g_VGuiPanel = IfaceMngr::Get().getIface<IPanel>("./bin/linux64/vgui2_client.so", "VGUI_Panel");
    g_DebugOverlay = IfaceMngr::Get().getIface<IVDebugOverlay>("./bin/linux64/engine_client.so", "VDebugOverlay");
    g_VGuiSurface = IfaceMngr::Get().getIface<ISurface>("./bin/linux64/vguimatsurface_client.so", "VGUI_Surface");
    g_MdlInfo = IfaceMngr::Get().getIface<IVModelInfoClient>("./bin/linux64/engine_client.so", "VModelInfoClient");
    g_MdlRender = IfaceMngr::Get().getIface<IVModelRender>("./bin/linux64/engine_client.so", "VEngineModel");
    g_RenderView = IfaceMngr::Get().getIface<IVRenderView>("./bin/linux64/engine_client.so", "VEngineRenderView");
    g_MatSystem = IfaceMngr::Get().getIface<IMaterialSystem>("./bin/linux64/materialsystem_client.so", "VMaterialSystem");
    g_GameEvents = IfaceMngr::Get().getIface<IGameEventManager2>("./bin/linux64/engine_client.so", "GAMEEVENTSMANAGER002", true);
    g_MdlCache = IfaceMngr::Get().getIface<IMDLCache>("./bin/linux64/datacache_client.so", "MDLCache");
    g_Prediction = IfaceMngr::Get().getIface<IPrediction>("./csgo/bin/linux64/client_panorama_client.so", "VClientPrediction");
    g_GameMovement = IfaceMngr::Get().getIface<CGameMovement>("./csgo/bin/linux64/client_panorama_client.so", "GameMovement");
    g_EngineSound = IfaceMngr::Get().getIface<IEngineSound>("./bin/linux64/engine_client.so", "IEngineSoundClient");
    g_PhysSurface = IfaceMngr::Get().getIface<IPhysicsSurfaceProps>("./bin/linux64/vphysics_client.so", "VPhysicsSurfaceProps");
    g_InputSystem = IfaceMngr::Get().getIface<IInputSystem>("./bin/linux64/inputsystem_client.so", "InputSystemVersion");
    g_InputInternal = IfaceMngr::Get().getIface<uintptr_t>("./bin/linux64/vgui2_client.so", "VGUI_InputInternal");
    g_Localize = IfaceMngr::Get().getIface<ILocalize>("./bin/linux64/localize_client.so", "Localize_");

    void *library = dlopen("./csgo/bin/linux64/client_panorama_client.so", RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL);
    if(library)
    {
        void *memAllocFn = dlsym(library, "g_pMemAlloc");
        if(!memAllocFn)
            dlclose(library);

        dlclose(library);

        g_pMemAlloc = *reinterpret_cast<IMemAlloc**>(memAllocFn);
    }

    // g_GlobalVars =
    // g_ClientMode =
    // g_ClientState =
    // g_GlowObjManager =
    // g_MoveHelper =
    // g_RenderBeams =
    // g_Input =

    NetMngr::Get().init();

    g_pVguiPanelHook = std::make_unique<ShadowVTManager>();
    //g_pClientModeHook = std::make_unique<ShadowVTManager>();

    g_pVguiPanelHook->Setup(g_VGuiPanel);
    //g_pClientModeHook->Setup(g_ClientMode);

    g_pVguiPanelHook->Hook(42, Hooks::PaintTraverse);
    //g_pClientModeHook->Hook(25, Hooks::CreateMove);

    o_PaintTraverse = g_pVguiPanelHook->GetOriginal<PaintTraverse_t>(42);
    //o_CreateMove = g_pClientModeHook->GetOriginal<CreateMove_t >(25);
}

void Installer::uninstallGladiator()
{
    g_pVguiPanelHook->RestoreTable();
    //g_pClientModeHook->RestoreTable();
}
