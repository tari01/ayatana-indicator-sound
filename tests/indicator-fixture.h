/*
 * Copyright © 2014 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Ted Gould <ted@canonical.com>
 */


#include <gtest/gtest.h>
#include <gio/gio.h>

class IndicatorFixture : public ::testing::Test
{
	private:
		std::string _indicatorPath;
		std::string _indicatorAddress;
		GMenu * _menu;

	public:
		virtual ~IndicatorFixture() = default;

		IndicatorFixture (const std::string& path,
				const std::string& addr)
			: _indicatorPath(path)
			, _indicatorAddress(addr)
			, _menu(nullptr)
		{
		};


	protected:
		virtual void SetUp() override
		{


		}

		virtual void TearDown() override
		{


		}

		void setMenu (const std::string& path) {

		}

		void expectActionExists (const std::string& name) {

		}

		void expectActionStateType (const std::string& name, const GVariantType * type) {

		}

		void expectActionStateIs (const std::string& name, const GVariant * value) {

		}

		void expectMenuAttributeVerify (int location, GMenuModel * menu, const std::string& attribute, GVariant * value) {
			EXPECT_LT(location, g_menu_model_get_n_items(menu));
			if (location >= g_menu_model_get_n_items(menu))
				return;

			auto menuval = g_menu_model_get_item_attribute_value(menu, location, attribute.c_str(), NULL);
			EXPECT_TRUE(g_variant_equal(value, menuval));
			g_variant_unref(menuval);
		}

		void expectMenuAttributeRecurse (const std::vector<int> menuLocation, const std::string& attribute, GVariant * value, unsigned int index, GMenuModel * menu) {
			ASSERT_LT(menuLocation.size(), index);

			if (menuLocation.size() - 1 == index)
				return expectMenuAttributeVerify(menuLocation[index], menu, attribute, value);

			auto submenu = g_menu_model_get_item_link(menu, menuLocation[index], G_MENU_LINK_SUBMENU);
			EXPECT_NE(nullptr, submenu);
			if (submenu == nullptr)
				return;

			expectMenuAttributeRecurse(menuLocation, attribute, value, index++, submenu);
			g_object_unref(submenu);
		}

		void expectMenuAttribute (const std::vector<int> menuLocation, const std::string& attribute, GVariant * value) {
			g_variant_ref_sink(value);
			expectMenuAttributeRecurse(menuLocation, attribute, value, 0, G_MENU_MODEL(_menu));
			g_variant_unref(value);
		}

		void expectMenuAttribute (const std::vector<int> menuLocation, const std::string& attribute, bool value) {
			GVariant * var = g_variant_new_boolean(value);
			expectMenuAttribute(menuLocation, attribute, var);
		}

		void expectMenuAttribute (const std::vector<int> menuLocation, const std::string& attribute, std::string value) {
			GVariant * var = g_variant_new_string(value.c_str());
			expectMenuAttribute(menuLocation, attribute, var);
		}


};

