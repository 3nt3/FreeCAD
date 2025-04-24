/***************************************************************************
 *   Copyright (c) 2025 3nt3 <nia@3nt3.de>                *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#include "TaskHoleBreakout.h"
#include "App/DocumentObject.h"
#include <string>
#include "ui_TaskHoleBreakout.h"

#include <Mod/TechDraw/App/DrawComplexSection.h>
#include <Mod/TechDraw/App/DrawPage.h>
#include <Mod/TechDraw/App/DrawUtil.h>
#include <Mod/TechDraw/App/DrawViewPart.h>
#include <Mod/TechDraw/App/Preferences.h>

using namespace Gui;
using namespace TechDraw;
using namespace TechDrawGui;
using DU = DrawUtil;


TaskHoleBreakout::TaskHoleBreakout(TechDraw::DrawPage* page,
                                   TechDraw::DrawViewPart* baseView,
                                   std::vector<App::DocumentObject*> shapes,
                                   std::vector<App::DocumentObject*> xShapes,
                                   App::DocumentObject* profileObject,
                                   std::vector<std::string> profileSubs)
    : ui(new Ui_TaskHoleBreakout)
    ,

    m_page(page)
    , m_baseView(baseView)
    , m_section(nullptr)
    , m_shapes(shapes)
    , m_xShapes(xShapes)
    , m_profileObject(profileObject)
    , m_profileSubs(profileSubs)
    , m_dirName("Aligned")
    , m_createMode(true)
    , m_applyDeferred(0)
    , m_angle(0.0)
    , m_directionIsSet(false)
    , m_modelIsDirty(false)
    , m_scaleEdited(false)
{
    // Setup UI
    m_ui = new Ui_TaskHoleBreakout();
    m_ui->setupUi(this);

    // Connect signals and slots
    connect(m_ui->buttonBox, &QDialogButtonBox::accepted, this, &TaskHoleBreakout::accept);
    connect(m_ui->buttonBox, &QDialogButtonBox::rejected, this, &TaskHoleBreakout::reject);
}
