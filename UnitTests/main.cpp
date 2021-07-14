//#include <QtCore/QCoreApplication>
#include <QtWidgets>
#include "gtest/gtest.h"

#include "hiberlite.h"
#include "ResourceManager.h"
#include "ProductDataManager.h"


TEST(DataManagerTest, RetrieveDataTest)
{
    ProductDataManager pdm;
    Lamp l{ pdm.get_item<Lamp>(1) };
    EXPECT_EQ(l.id, 1);
    //ResourceManager rm;
    //std::vector<unsigned char> v{rm.get_doc("Catalog.pdf") };
    //EXPECT_EQ(v.size(), 18375382);
}

TEST(FirstTest, TestResult)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}