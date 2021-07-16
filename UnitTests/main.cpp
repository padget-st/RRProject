#include <QtCore/QCoreApplication>
#include <QtWidgets>
#include <vector>
#include "gtest/gtest.h"

#include "ScreenStack.h"

namespace UnitTests
{
    constexpr int TEST_ID{ 1 };
    constexpr int TEST_ZERO_ID{ 0 };
    constexpr int TEST_UNREAL_ID{ 9'999'999 };
    namespace DataLayer
    {
        //ProductDataManager-----------------------------------------------------------------------------------
        template<typename T>
        class ItemDataManagerTest : public ::testing::Test
        {
        protected:
            ItemDataManagerTest() : v{ pdm.get_all<T>() }
            {}
            ProductDataManager pdm;
            std::vector<T> v;
        };
        using MyTypesItems = ::testing::Types<Lamp, ProductGroup, ItemDocument, Contact, Suggestion>;
        TYPED_TEST_SUITE(ItemDataManagerTest, MyTypesItems);

        TYPED_TEST(ItemDataManagerTest, GetValidItemData)
        {
            EXPECT_TRUE(this->v.size());
            if (v.size() >= 2)
            {
                for (int i{}; i <= v.size() - 2; i++)
                {
                    EXPECT_NE(v[i].id, v[i + 1].id);
                }
            }
            EXPECT_EQ(this->pdm.get_item<TypeParam>(TEST_ID).id, TEST_ID);
            EXPECT_EQ(this->pdm.get_all<TypeParam>().size(), v.size());
            TypeParam item;
            EXPECT_NO_THROW(this->pdm.save_item<TypeParam>(item));
        }

        TYPED_TEST(ItemDataManagerTest, GetInvalidItemData)
        {
            EXPECT_ANY_THROW(this->pdm.get_item<TypeParam>(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->pdm.get_item<TypeParam>(TEST_UNREAL_ID));
        }

        template<typename T>
        class GroupedDataManagerTest : public ::testing::Test
        {
        protected:
            GroupedDataManagerTest() : v_gr{ pdm.get_grouped<T>(TEST_ID) }
            {}
            ProductDataManager pdm;
            std::vector<T> v_gr;
        };
        using MyTypesGroups = ::testing::Types<Lamp, ItemDocument>;
        TYPED_TEST_SUITE(GroupedDataManagerTest, MyTypesGroups);

        TYPED_TEST(GroupedDataManagerTest, GetValidGroupedData)
        {
            EXPECT_EQ(this->pdm.get_grouped<TypeParam>(1).size(), v_gr.size());
            EXPECT_NO_THROW(this->pdm.get_grouped<TypeParam>(1));
        }

        TYPED_TEST(GroupedDataManagerTest, GetInvalidGroupedData)
        {
            EXPECT_ANY_THROW(this->pdm.get_grouped<TypeParam>(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->pdm.get_grouped<TypeParam>(TEST_UNREAL_ID));
        }
    }
    
    namespace ServiceLayer
    {
        //ResourceManager-----------------------------------------------------------------------------------
        class ResourceManagerTest : public ::testing::Test
        {
        protected:
            ResourceManager rm;
        };

        TEST_F(ResourceManagerTest, GetValidResources)
        {
            EXPECT_EQ(rm.get_banner().size(), 6623);
            EXPECT_NO_THROW(rm.get_banner());
            EXPECT_EQ(rm.get_doc("ISO9001_2015.pdf").size(), 514837);
            EXPECT_EQ(rm.get_doc("Specifications_DKU-01.pdf").size(), 364576);
            EXPECT_NO_THROW(rm.get_doc("Catalog.pdf"));
            EXPECT_EQ(rm.get_icon("DBO-01/dbo01-area.jpg").size(), 51053);
            EXPECT_EQ(rm.get_icon("DKU-01/dku01-3.jpg").size(), 48054);
            EXPECT_NO_THROW(rm.get_icon("DVO-01/dvo01-3.jpg"));
        }

        TEST_F(ResourceManagerTest, GetInvalidResources)
        {
            EXPECT_ANY_THROW(rm.get_doc("WrongDoc.pdf"));
            EXPECT_ANY_THROW(rm.get_icon("WrongIcon.jpg"));
        }

        //ProductManager,DocumentManager--------------------------------------------------------------------
        template<typename T>
        class ProdDocManagerTest : public ::testing::Test
        {
        protected:
            T manager;
        };
        using MyTypes = ::testing::Types<ProductManager, DocumentManager>;
        TYPED_TEST_SUITE(ProdDocManagerTest, MyTypes);

        TYPED_TEST(ProdDocManagerTest, GetValidData)
        {
            ASSERT_NO_THROW(this->manager.get_all());
            auto v{ this->manager.get_all() };
            EXPECT_TRUE(v.size());
            for (auto elem : v)
            {
                EXPECT_TRUE(elem.id);
            }

            ASSERT_NO_THROW(this->manager.get_grouped(TEST_ID));
            auto v_gr{ this->manager.get_grouped(TEST_ID) };
            for (auto elem : v_gr)
            {
                EXPECT_EQ(elem.outer_group_id, TEST_ID);
            }

            ASSERT_NO_THROW(this->manager.get_item(TEST_ID));
            for (auto elem : v)
            {
                auto item{ this->manager.get_item(elem.id) };
                EXPECT_EQ(elem.id, item.id);
            }
        }

        TYPED_TEST(ProdDocManagerTest, GetInvalidData)
        {
            EXPECT_ANY_THROW(this->manager.get_grouped(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->manager.get_grouped(TEST_UNREAL_ID));
            EXPECT_ANY_THROW(this->manager.get_item(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->manager.get_item(TEST_UNREAL_ID));
        }

        //ContactManager-----------------------------------------------------------------------------------
        class ContactManagerTest : public ::testing::Test
        {
        protected:
            ContactManagerTest() :
                main_cont{ cm.get_contact() }, v{cm.get_all_sug()}
            {}
            ContactManager cm;
            std::vector<Suggestion> v;
            Contact main_cont;
        };

        TEST_F(ContactManagerTest, GetValidContact)
        {
            ASSERT_NO_THROW(this->cm.get_contact());
            auto cont{ cm.get_contact() };
            EXPECT_EQ(main_cont.id, cont.id);
            EXPECT_EQ(main_cont.name, cont.name);
        }

        TEST_F(ContactManagerTest, GetValidSuggestion)
        {
            ASSERT_NO_THROW(this->cm.get_all_sug());
            auto v_sug{ this->cm.get_all_sug() };
            EXPECT_TRUE(v_sug.size());
            for (int i{}; i < v_sug.size(); i++)
            {
                EXPECT_EQ(v[i].id, v_sug[i].id);
                EXPECT_EQ(v[i].name, v_sug[i].name);
            }

            ASSERT_NO_THROW(this->cm.get_suggestion(TEST_ID));
            EXPECT_EQ(this->cm.get_suggestion(TEST_ID).id, TEST_ID);

            Suggestion test_sug;
            ASSERT_NO_THROW(this->cm.save_suggestion(test_sug));
        }
        
        TEST_F(ContactManagerTest, GetInvalidSuggestion)
        {
            EXPECT_ANY_THROW(this->cm.get_suggestion(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->cm.get_suggestion(TEST_UNREAL_ID));
        }

        //GroupManager-----------------------------------------------------------------------------------
        class GroupManagerTest : public ::testing::Test
        {
        protected:
            GroupManagerTest() :
                v{gm.get_all()}, test_gr{gm.get_item(TEST_ID)}
            {}
            GroupManager gm;
            std::vector<ProductGroup> v;
            ProductGroup test_gr;
        };

        TEST_F(GroupManagerTest, GetValidGroup)
        {
            ASSERT_NO_THROW(this->gm.get_all());
            auto v_gr{ this->gm.get_all() };
            EXPECT_TRUE(v_gr.size());
            for (int i{}; i < v_gr.size(); i++)
            {
                EXPECT_EQ(v[i].id, v_gr[i].id);
                EXPECT_EQ(v[i].group_name, v_gr[i].group_name);
            }

            ASSERT_NO_THROW(this->gm.get_item(TEST_ID));
            EXPECT_EQ(this->gm.get_item(TEST_ID).id, test_gr.id);
        }

        TEST_F(GroupManagerTest, GetInvalidGroup)
        {
            EXPECT_ANY_THROW(this->gm.get_item(TEST_ZERO_ID));
            EXPECT_ANY_THROW(this->gm.get_item(TEST_UNREAL_ID));
        }
    }

    namespace GUILayer
    {
        class ScreenTest : public ::testing::Test
        {
        protected:
            ScreenTest() : n{ 0 }, m_Qapp{nullptr}
            {}
            ~ScreenTest()
            {
                delete m_Qapp;
            }
            void SetUp() override
            {
                m_Qapp = new QApplication(n, nullptr);
            }
            void TearDown() override
            {
                m_Qapp->exec();
            }
            QApplication* m_Qapp;
            int n;
        };
        
        TEST_F(ScreenTest, MainScreenCorrectWork)
        {
            MainScreen* ms{ new MainScreen };
            ASSERT_NO_THROW(ms->show());
        }

        TEST_F(ScreenTest, GroupScreenCorrectWork)
        {
            GroupManager pm;
            GroupScreen* gs{ new GroupScreen(pm.get_item(TEST_ID)) };
            ASSERT_NO_THROW(gs->show());
        }

        TEST_F(ScreenTest, LampScreenCorrectWork)
        {
            ProductManager pm;
            LampScreen* ls{ new LampScreen(pm.get_item(TEST_ID)) };
            ASSERT_NO_THROW(ls->show());
        }

        TEST_F(ScreenTest, DocScreenCorrectWork)
        {
            DocumentScreen* ds{ new DocumentScreen() };
            ASSERT_NO_THROW(ds->show());
        }

        TEST_F(ScreenTest, DownloadDocScreenCorrectWork)
        {
            DocumentManager dm;
            DownloadDocScreen* dds{ new DownloadDocScreen(dm.get_item(TEST_ID)) };
            ASSERT_NO_THROW(dds->show());
        }

        TEST_F(ScreenTest, ContactScreenCorrectWork)
        {
            ContactManager cm;
            ContactScreen* cs{ new ContactScreen(cm.get_contact()) };
            ASSERT_NO_THROW(cs->show());
        }

        TEST_F(ScreenTest, SuggestScreenCorrectWork)
        {
            ContactManager cm;
            SuggestionScreen* ss{ new SuggestionScreen() };
            ASSERT_NO_THROW(ss->show());
        }

        TEST_F(ScreenTest, ScreenStackCorrectWork)
        {
            ScreenStack* ss{ new ScreenStack() };
            ASSERT_NO_THROW(ss->show());
        }
    }
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}