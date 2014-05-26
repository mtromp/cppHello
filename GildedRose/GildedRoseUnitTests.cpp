#include <gtest/gtest.h>

#include "GildedRose.h"
class GildedRoseTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {
        for(int i =0; i<items.size(); ++i)
        {
            delete items[i];
        }
    }

    vector<Item*> items;
};

TEST_F(GildedRoseTest, ItemsAreNamed)
{
    items.push_back(new Item("Normal", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Normal", app.items[0]->name);
}

TEST_F(GildedRoseTest, NormalItemDegradesTwiceAsQuicklyWhenSellInIsZero)
{
    items.push_back(new Item("Normal", 0, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(3, app.items[0]->quality);
}

TEST_F(GildedRoseTest, NormalItemDegradesBy1Quality)
{
    items.push_back(new Item("Normal", 1, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(4, app.items[0]->quality);
    EXPECT_EQ(0, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, QualityOfANormalItemIsNeverNegativeAtNormalRate)
{
    items.push_back(new Item("Normal", 1, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0]->quality);
}

TEST_F(GildedRoseTest, QualityOfANormalItemIsNeverNegativeAtTwiceRate)
{
    items.push_back(new Item("Normal", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0]->quality);
}

TEST_F(GildedRoseTest, QualityOfAgedBrieIncreases)
{
    items.push_back(new Item("Aged Brie", 10, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(11, app.items[0]->quality);
}

TEST_F(GildedRoseTest, QualityOfAgedBrieIsNeverAbove50)
{
    items.push_back(new Item("Aged Brie", 10, 50));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(50, app.items[0]->quality);
    EXPECT_EQ(9, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, SulfurasNeverExpireOrLoseQuality)
{
    items.push_back(new Item("Sulfuras, Hand of Ragnaros", 0, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(80, app.items[0]->quality);
    EXPECT_EQ(0, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, BackstagePassIncreaseInQuality)
{
    items.push_back(new Item("Backstage passes to a TAFKAL80ETC concert", 30, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(11, app.items[0]->quality);
    EXPECT_EQ(29, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, BackstagePassIncreaseInQualityBy2Inside10Days)
{
    items.push_back(new Item("Backstage passes to a TAFKAL80ETC concert", 10, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(12, app.items[0]->quality);
    EXPECT_EQ(9, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, BackstagePassIncreaseInQualityBy3Inside5Days)
{
    items.push_back(new Item("Backstage passes to a TAFKAL80ETC concert", 5, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(13, app.items[0]->quality);
    EXPECT_EQ(4, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, BackstagePassHaveNoValueAfterTheConcern)
{
    items.push_back(new Item("Backstage passes to a TAFKAL80ETC concert", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0]->quality);
    EXPECT_EQ(-1, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, DISABLED_ConjuredItemQualityDropsBy2PerTick)
{
    items.push_back(new Item("Conjured Mana Cake", 12, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(8, app.items[0]->quality);
    EXPECT_EQ(11, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, DISABLED_ConjuredItemQualityHasAFloorOfZero)
{
    items.push_back(new Item("Conjured Mana Cake", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0]->quality);
    EXPECT_EQ(-1, app.items[0]->sellIn);
}

TEST_F(GildedRoseTest, DISABLED_ConjuredItemQualityGoesDownBy4AfterSellBy)
{
    items.push_back(new Item("Conjured Mana Cake", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(6, app.items[0]->quality);
    EXPECT_EQ(-1, app.items[0]->sellIn);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

