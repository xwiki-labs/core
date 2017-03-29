﻿/*
 * (c) Copyright Ascensio System SIA 2010-2017
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "draw_page.h"

#include <cpdoccore/xml/xmlchar.h>
#include <cpdoccore/xml/attributes.h>

#include "office_elements_create.h"

#include <cpdoccore/xml/simple_xml_writer.h>

namespace cpdoccore { 

	using namespace odf_types;

namespace odf_writer {


void draw_page_attr::add_attributes( const xml::attributes_wc_ptr & Attributes )
{
    CP_APPLY_ATTR(L"draw:id",			draw_id_);

    CP_APPLY_ATTR(L"draw:name",			draw_name_);
    CP_APPLY_ATTR(L"draw:style-name",	draw_style_name_);
    
	CP_APPLY_ATTR(L"presentation:presentation-page-layout-name", page_layout_name_);
    CP_APPLY_ATTR(L"draw:master-page-name",				master_page_name_);
    
	CP_APPLY_ATTR(L"presentation:use-date-time-name",	use_date_time_name_);
    CP_APPLY_ATTR(L"presentation:use-footer-name",		use_footer_name_);

}

//////////////////////////////////////////////////////////////////////////////////////////////////
const wchar_t * draw_page::ns = L"draw";
const wchar_t * draw_page::name = L"page";

void draw_page::create_child_element( const std::wstring & Ns, const std::wstring & Name)
{
	if	CP_CHECK_NAME(L"anim", L"par") 
		CP_CREATE_ELEMENT(animation_);
	else
		CP_CREATE_ELEMENT(content_);
}
void draw_page::add_child_element( const office_element_ptr & child_element)
{
	ElementType type = child_element->get_type();
	if(type == typeAnimPar)
		animation_ = child_element;
	else
		content_.push_back(child_element);
}

void draw_page::add_attributes( const xml::attributes_wc_ptr & Attributes )
{
    draw_page_attr_.add_attributes(Attributes);
}
void draw_page::serialize(std::wostream & _Wostream)
{
    CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			for (int i = 0; i < content_.size(); i++)
			{
				content_[i]->serialize(CP_XML_STREAM());
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
const wchar_t * presentation_footer_decl::ns = L"presentation";
const wchar_t * presentation_footer_decl::name = L"footer-decl";

void presentation_footer_decl::add_attributes( const xml::attributes_wc_ptr & Attributes )
{
	CP_APPLY_ATTR(L"presentation:name",	presentation_name_);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
const wchar_t * presentation_date_time_decl::ns = L"presentation";
const wchar_t * presentation_date_time_decl::name = L"date-time-decl";

void presentation_date_time_decl::add_attributes( const xml::attributes_wc_ptr & Attributes )
{
	CP_APPLY_ATTR(L"presentation:name",		presentation_name_);
	CP_APPLY_ATTR(L"presentation:source",	presentation_source_);
	CP_APPLY_ATTR(L"style:data-style-name",	style_data_style_name_);
}


}
}
