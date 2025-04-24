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

#ifndef TECHDRAWGUI_TASKHOLEBREAKOUT_H
#define TECHDRAWGUI_TASKHOLEBREAKOUT_H

#include <QString>

#include <Base/Vector3D.h>
#include <Gui/TaskView/TaskDialog.h>
#include <Gui/TaskView/TaskView.h>
#include <Mod/TechDraw/TechDrawGlobal.h>


namespace App
{
class DocumentObject;
}

namespace TechDraw
{
class DrawPage;
class DrawView;
class DrawViewPart;
class DrawComplexSection;
}  // namespace TechDraw

namespace TechDrawGui
{

class Ui_TaskHoleBreakout;

class TaskHoleBreakout: public QWidget
{
    Q_OBJECT

public:
    TaskHoleBreakout(TechDraw::DrawPage* page,
                     TechDraw::DrawViewPart* baseView,
                     std::vector<App::DocumentObject*> shapes,
                     std::vector<App::DocumentObject*> xShapes,
                     App::DocumentObject* profileObject,
                     std::vector<std::string> profileSubs);

private:
    TechDraw::DrawPage* m_page;
    App::Document* m_doc;
    TechDraw::DrawViewPart* m_baseView;
    TechDraw::DrawComplexSection* m_section;
    std::vector<App::DocumentObject*> m_shapes;
    std::vector<App::DocumentObject*> m_xShapes;
    App::DocumentObject* m_profileObject;
    std::vector<std::string> m_profileSubs;
};

}  // namespace TechDrawGui

#endif
