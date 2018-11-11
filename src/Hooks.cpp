//
// Created by assemble on 11.11.18.
//

#include "Gamehooking.h"

void Hooks::PaintTraverse(void* thisptr, void*, unsigned int panel, bool forceRepaint, bool allowForce)
{
    static uint32_t HudZoomPanel;

    if (!HudZoomPanel)
    {
        if (!strcmp("HudZoom", g_VGuiPanel->GetName(panel)))
            HudZoomPanel = panel;
    }

    o_PaintTraverse(thisptr, panel, forceRepaint, allowForce);

    static uint32_t FocusOverlayPanel;
    if (!FocusOverlayPanel)
    {
        if (strstr(g_VGuiPanel->GetName(panel), "MatSystemTopPanel"))
            FocusOverlayPanel = panel;
    }

    if (panel == FocusOverlayPanel)
    {

    }
}