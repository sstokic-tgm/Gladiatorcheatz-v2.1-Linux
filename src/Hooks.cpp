//
// Created by assemble on 11.11.18.
//

#include "Gamehooking.h"
#include "GitRevision.h"

namespace Global
{
    float smt = 0.f;
    QAngle visualAngles = QAngle(0.f, 0.f, 0.f);
    bool bSendPacket = false;
    bool bAimbotting = false;
    bool bVisualAimbotting = false;
    QAngle vecVisualAimbotAngs = QAngle(0.f, 0.f, 0.f);
    CUserCmd *userCMD = nullptr;

    bool bFakelag = false;
    float flFakewalked = 0.f;
    Vector vecUnpredictedVel = Vector(0, 0, 0);

    std::array<std::string, 64> resolverModes;
}

void Hooks::PaintTraverse(void* thisptr, unsigned int panel, bool forceRepaint, bool allowForce)
{
    o_PaintTraverse(thisptr, panel, forceRepaint, allowForce);

    static uint32_t FocusOverlayPanel;
    if (!FocusOverlayPanel)
    {
        if (strstr(g_VGuiPanel->GetName(panel), "MatSystemTopPanel"))
            {
                FocusOverlayPanel = panel;

                g_EngineClient->ExecuteClientCmd("clear");
                g_CVar->ConsoleColorPrintf(Color(0, 153, 204, 255), "%s\n", GitRevision::GetFullVersion());
                g_EngineClient->ExecuteClientCmd("version");
                g_EngineClient->ExecuteClientCmd("toggleconsole");
            }
    }

    if (panel == FocusOverlayPanel)
    {

    }
}

bool Hooks::CreateMove(float smt, CUserCmd *userCMD)
{
    if (!userCMD->command_number || !g_EngineClient->IsInGame() || !g_LocalPlayer || !g_LocalPlayer->IsAlive())
        return o_CreateMove(g_ClientMode, smt, userCMD);

    //https://www.unknowncheats.me/forum/counterstrike-global-offensive/290258-updating-bsendpacket-linux.html
    uintptr_t rbp;
    asm volatile("mov %%rbp, %0" : "=r" (rbp));
    bool *SendPacket = ((*(bool **)rbp) - 0x18);
    *SendPacket = Global::bSendPacket;

    Global::smt = smt;
    Global::bFakelag = false;
    Global::bSendPacket = true;
    Global::userCMD = userCMD;
    Global::vecUnpredictedVel = g_LocalPlayer->m_vecVelocity();

    return false;
}
