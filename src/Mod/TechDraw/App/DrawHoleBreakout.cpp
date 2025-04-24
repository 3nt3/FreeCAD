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

#include "DrawHoleBreakout.h"

using namespace TechDraw;


TechDraw::DrawHoleBreakout::DrawHoleBreakout()
{
    static const char* fgroup = "Cutting Tool";

    ADD_PROPERTY_TYPE(CuttingToolWireObject,
                      (nullptr),
                      fgroup,
                      App::Prop_None,
                      "A sketch that describes the cutting tool");
    CuttingToolWireObject.setScope(App::LinkScope::Global);
    ProjectionStrategy.setEnums(ProjectionStrategyEnums);
    ADD_PROPERTY_TYPE(ProjectionStrategy,
                      ((long)0),
                      fgroup,
                      App::Prop_None,
                      "Make a single cut, or use the profile in pieces");
}
