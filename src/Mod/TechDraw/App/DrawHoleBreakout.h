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

#ifndef DrawHoleBreakout_h_
#define DrawHoleBreakout_h_

#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawViewSection.h"

namespace TechDraw
{

class TechDrawExport DrawHoleBreakout: public DrawViewSection
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawHoleBreakout);

public:
    DrawHoleBreakout();
    ~DrawHoleBreakout() override = default;

    App::PropertyLink CuttingToolWireObject;
    App::PropertyEnumeration ProjectionStrategy;  // Offset or Aligned

    TopoDS_Shape makeCuttingTool(double dMax) override;

private:
    static constexpr char* ProjectionStrategyEnums[] = {"Offset", "Aligned", "NoParallel", nullptr};
};

}  // namespace TechDraw

#endif
