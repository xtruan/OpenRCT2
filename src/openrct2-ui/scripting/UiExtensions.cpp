/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "UiExtensions.h"

#include "CustomMenu.h"
#include "ScUi.hpp"
#include "ScWindow.hpp"

#include <openrct2/scripting/ScriptEngine.h>

using namespace OpenRCT2::Scripting;

void UiScriptExtensions::Extend(ScriptEngine& scriptEngine)
{
    auto ctx = scriptEngine.GetContext();

    dukglue_register_global(ctx, std::make_shared<ScUi>(scriptEngine), "ui");

    ScUi::Register(ctx);
    ScViewport::Register(ctx);
    ScWindow::Register(ctx);

    InitialiseCustomMenuItems(scriptEngine);
}
