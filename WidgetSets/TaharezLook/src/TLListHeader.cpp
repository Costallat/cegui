/************************************************************************
	filename: 	TLListHeader.cpp
	created:	14/6/2004
	author:		Paul D Turner
	
	purpose:	Implementation of Taharez MultiColumn list header widget.
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "TLListHeader.h"
#include "CEGUIWindowManager.h"
#include "TLListHeaderSegment.h"

// Start of CEGUI namespace section
namespace CEGUI
{
/*************************************************************************
	Constants
*************************************************************************/
// type name for this widget
const utf8	TLListHeader::WidgetTypeName[]	= "TaharezLook/ListHeader";

// type names for the component widgets
const utf8* TLListHeader::SegmentWidgetType		= TLListHeaderSegment::WidgetTypeName;


/*************************************************************************
	Constructor
*************************************************************************/
TLListHeader::TLListHeader(const String& type, const String& name) :
	ListHeader(type, name)
{
}


/*************************************************************************
	Destructor
*************************************************************************/
TLListHeader::~TLListHeader(void)
{
}

	
/*************************************************************************
	Render the widget.
*************************************************************************/
void TLListHeader::drawSelf(float z)
{
}


/*************************************************************************
	Create and return a pointer to a new ListHeaderSegment based object.
*************************************************************************/
ListHeaderSegment* TLListHeader::createNewSegment(const String& name) const
{
	return (ListHeaderSegment*)WindowManager::getSingleton().createWindow(SegmentWidgetType, name);
}


/*************************************************************************
	Cleanup and destroy the given ListHeaderSegment that was created
	via the createNewSegment method.
*************************************************************************/
void TLListHeader::destroyListSegment(ListHeaderSegment* segment) const
{
	WindowManager::getSingleton().destroyWindow(segment);
}


//////////////////////////////////////////////////////////////////////////
/*************************************************************************

	Factory Methods

*************************************************************************/
//////////////////////////////////////////////////////////////////////////
/*************************************************************************
	Create, initialise and return a TLListHeader
*************************************************************************/
Window* TLListHeaderFactory::createWindow(const String& name)
{
	return new TLListHeader(d_type, name);
}


} // End of  CEGUI namespace section