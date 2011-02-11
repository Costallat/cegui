/************************************************************************
    filename:   CEGUIFalWidgetLookFeel.h
    created:    Mon Jun 13 2005
    author:     Paul D Turner <paul@cegui.org.uk>
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
#ifndef _CEGUIFalWidgetLookFeel_h_
#define _CEGUIFalWidgetLookFeel_h_

#include "falagard/CEGUIFalStateImagery.h"
#include "falagard/CEGUIFalWidgetComponent.h"
#include "falagard/CEGUIFalImagerySection.h"
#include "falagard/CEGUIFalPropertyInitialiser.h"
#include "falagard/CEGUIFalPropertyDefinition.h"
#include "falagard/CEGUIFalNamedArea.h"
#include <map>

// Start of CEGUI namespace section
namespace CEGUI
{
    /*!
    \brief
        Class that encapsulates look & feel information for a particular widget type.
    */
    class CEGUIBASE_API WidgetLookFeel
    {
    public:
        WidgetLookFeel(const String& name);
        WidgetLookFeel() {}

        /*!
        \brief
            Return a const reference to the StateImagery object for the specified state.

        \return
            StateImagery object for the requested state.
        */
        const StateImagery& getStateImagery(const CEGUI::String& state) const;

        /*!
        \brief
            Return a const reference to the ImagerySection object with the specified name.

        \return
            ImagerySection object with the specified name.
        */
        const ImagerySection& getImagerySection(const CEGUI::String& section) const;

        /*!
        \brief
            Return the name of the widget look.

        \return
            String object holding the name of the WidgetLookFeel.
        */
        const String& getName() const;

        /*!
        \brief
            Add an ImagerySection to the WidgetLookFeel.

        \param section
            ImagerySection object to be added.

        \return Nothing.
        */
        void addImagerySection(const ImagerySection& section);

        /*!
        \brief
            Add a WidgetComponent to the WidgetLookFeel.

        \param widget
            WidgetComponent object to be added.

        \return Nothing.
        */
        void addWidgetComponent(const WidgetComponent& widget);

        /*!
        \brief
            Add a state specification (StateImagery object) to the WidgetLookFeel.

        \param section
            StateImagery object to be added.

        \return Nothing.
        */
        void addStateSpecification(const StateImagery& state);

        /*!
        \brief
            Add a property initialiser to the WidgetLookFeel.

        \param initialiser
            PropertyInitialiser object to be added.

        \return Nothing.
        */
        void addPropertyInitialiser(const PropertyInitialiser& initialiser);

        /*!
        \brief
            Clear all ImagerySections from the WidgetLookFeel.

        \return
            Nothing.
        */
        void clearImagerySections();

        /*!
        \brief
            Clear all WidgetComponents from the WidgetLookFeel.

        \return
            Nothing.
        */
        void clearWidgetComponents();

        /*!
        \brief
            Clear all StateImagery objects from the WidgetLookFeel.

        \return
            Nothing.
        */
        void clearStateSpecifications();

        /*!
        \brief
            Clear all PropertyInitialiser objects from the WidgetLookFeel.

        \return
            Nothing.
        */
        void clearPropertyInitialisers();

        /*!
        \brief
            Initialise the given window using PropertyInitialsers and component widgets
            specified for this WidgetLookFeel.

        \param widget
            Window based object to be initialised.

        \return
            Nothing.
        */
        void initialiseWidget(Window& widget) const;

        /*!
        \brief
            Return whether imagery is defined for the given state.

        \param state
            String object containing name of state to look for.

        \return
            - true if imagery exists for the specified state,
            - false if no imagery exists for the specified state.
        */
        bool isStateImageryPresent(const String& state) const;

        void addNamedArea(const NamedArea& area);
        void clearNamedAreas();
        const NamedArea& getNamedArea(const String& name) const;
        bool isNamedAreaDefined(const String& name) const;

        void layoutChildWidgets(const Window& owner) const;

    private:
        typedef std::map<String, StateImagery>    StateList;
        typedef std::map<String, ImagerySection>  ImageryList;
        typedef std::map<String, WidgetComponent> WidgetList;
        typedef std::map<String, NamedArea>       NamedAreaList;
        typedef std::vector<PropertyInitialiser>  PropertyList;
        typedef std::vector<PropertyDefinition>   PropertyDefinitionList;

        CEGUI::String   d_lookName;         //!< Name of this WidgetLookFeel.
        ImageryList     d_imagerySections;  //!< Collection of ImagerySection objects.
        WidgetList      d_childWidgets;     //!< Collection of WidgetComponent objects.
        StateList       d_stateImagery;     //!< Collection of StateImagery objects.
        PropertyList    d_properties;       //!< Collection of PropertyInitialser objects.
        NamedAreaList   d_namedAreas;       //!< Collection of NamedArea objects.
        PropertyDefinitionList  d_propertyDefinitions;  //!< Collection of PropertyDefinition objects.
    };


} // End of  CEGUI namespace section


#endif  // end of guard _CEGUIFalWidgetLookFeel_h_