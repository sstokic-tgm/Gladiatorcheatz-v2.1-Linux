//
// Created by assemble on 11.11.18.
//

#include "Gamehooking.h"
#include "GitRevision.h"

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
