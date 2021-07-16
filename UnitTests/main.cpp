#include <QtCore/QCoreApplication>
#include <QtWidgets>
#include <vector>
#include "gtest/gtest.h"

#include "ScreenStack.h"

namespace UnitTests
{
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
            EXPECT_EQ(this->pdm.get_item<TypeParam>(1).id, 1);
            EXPECT_EQ(this->pdm.get_all<TypeParam>().size(), v.size());
            TypeParam item;
            EXPECT_NO_THROW(this->pdm.save_item<TypeParam>(item));
        }

        TYPED_TEST(ItemDataManagerTest, GetInvalidItemData)
        {
            EXPECT_ANY_THROW(this->pdm.get_item<TypeParam>(0));
            EXPECT_ANY_THROW(this->pdm.get_item<TypeParam>(999'999));
        }

        template<typename T>
        class GroupedDataManagerTest : public ::testing::Test
        {
        protected:
            GroupedDataManagerTest() : v_gr{ pdm.get_grouped<T>(1) }
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
            EXPECT_ANY_THROW(this->pdm.get_grouped<TypeParam>(0));
            EXPECT_ANY_THROW(this->pdm.get_grouped<TypeParam>(999'999));
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

            ASSERT_NO_THROW(this->manager.get_grouped(1));
            auto v_gr{ this->manager.get_grouped(1) };
            for (auto elem : v_gr)
            {
                EXPECT_EQ(elem.outer_group_id, 1);
            }

            ASSERT_NO_THROW(this->manager.get_item(1));
            for (auto elem : v)
            {
                auto item{ this->manager.get_item(elem.id) };
                EXPECT_EQ(elem.id, item.id);
            }
        }

        TYPED_TEST(ProdDocManagerTest, GetInvalidData)
        {
            EXPECT_ANY_THROW(this->manager.get_grouped(0));
            EXPECT_ANY_THROW(this->manager.get_grouped(999'999));
            EXPECT_ANY_THROW(this->manager.get_item(0));
            EXPECT_ANY_THROW(this->manager.get_item(999'999));
        }

        //ContactManager-----------------------------------------------------------------------------------
        class ContactManagerTest : public ::testing::Test
        {
        protected:
            ContactManager cm;
        };

        TEST_F(ContactManagerTest, GetValidContact)
        {

        }
    }
}
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}