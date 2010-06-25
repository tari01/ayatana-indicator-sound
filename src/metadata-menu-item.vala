/*
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

using Dbusmenu;
using Gee;
using DbusmenuMetadata;

public class MetadataMenuitem : PlayerItem
{
	public MetadataMenuitem()
  {
		this.property_set(MENUITEM_PROP_TYPE, MENUITEM_TYPE);
	}

	public static HashSet<string> attributes_format()
	{
		HashSet<string> attrs = new HashSet<string>();		
		attrs.add(MENUITEM_TEXT_TITLE);
    attrs.add(MENUITEM_TEXT_ARTIST);
    attrs.add(MENUITEM_TEXT_ALBUM);
    attrs.add(MENUITEM_ARTURL);
		return attrs;
	}

	public override void check_layout(){
		this.property_set_bool(MENUITEM_PROP_VISIBLE, this.populated()); 
		debug("check layout for the metadata = %s", this.populated().to_string()); 
	}
	
	public bool populated()
	{
		return (this.property_get(MENUITEM_TEXT_TITLE) != null && 
		        this.property_get(MENUITEM_TEXT_TITLE) != "");
	}
		
}