//
// Created by AlisiaSmith on 17.09.18.
//

#include "Header.h"
#include "HashTable.h"
#include "Value.h"
#include "Pair.h"
#include <gtest/gtest.h>

 TEST(Hashtable, BasicTest)
 {
    HashTable ht;
    ht.insert("abc", Value());
    EXPECT_EQ(Value(), ht.at("abc"));
 }


TEST (Value, vl_functions)
{
	Value vl;

	EXPECT_EQ("Ivanov Ivan Ivanivich", vl.get_name());
	EXPECT_EQ(23, vl.get_age());
	EXPECT_EQ(78, vl.get_weight());

	Value vl2("Sasha", 28, 72);

	EXPECT_EQ("Sasha", vl2.get_name());
	EXPECT_EQ(28, vl2.get_age());
	EXPECT_EQ(72, vl2.get_weight());

	Value vl3 = vl2;

	EXPECT_TRUE(vl3 == vl2);
	EXPECT_TRUE(vl3 != vl);

	EXPECT_FALSE(vl3 == vl);
	EXPECT_FALSE(vl3 != vl2);

	vl = vl2;

	EXPECT_TRUE(vl == vl2);
	EXPECT_FALSE(vl != vl2);

}


TEST (Pairs, pa_functions)
{
    Value v("Tanya", 38, 74);
    Pair p1(v, "abc");
    Pair p2 = p1;
    Value t("Anna", 20, 55);

    EXPECT_TRUE(p1 == p2);

    p1.insert_back(t, "bcd");

    Pair tmp(t, "bcd");

    p2.put_next(tmp);


    EXPECT_TRUE(t == p1.get_next()->get_value());
    EXPECT_TRUE(t == p2.get_next()->get_value());

    EXPECT_TRUE("bcd" == p1.get_next()->get_key());
    EXPECT_TRUE("bcd" == p2.get_next()->get_key());


    EXPECT_TRUE(p1 == p2);

    p1.insert_back(t, "CCC");

    EXPECT_FALSE(p1 == p2);

    p2.insert_back(t, "CCC");

    EXPECT_TRUE(p1 == p2);

    EXPECT_EQ("abc", p1.get_key());
/*
    p1.clear();

    EXPECT_EQ("bcd", p1.get_key());

*/
}

TEST(HashTable, constructs)
{
    HashTable ht2;
    HashTable ht3(3);
    HashTable ht4 = ht3;

    EXPECT_TRUE(ht2.empty());
    EXPECT_TRUE(ht3.empty());
    EXPECT_TRUE(ht4.empty());

    EXPECT_TRUE(ht4 == ht3);

   /* EXPECT_EQ(0, ht2.size());
    EXPECT_EQ(0, ht3.size());
    EXPECT_EQ(0, ht4.size());

   /* EXPECT_EQ(727, ht2.size_ht());
    EXPECT_EQ(3, ht3.size_ht());
    EXPECT_EQ(3, ht4.size_ht());
*/
}

int main (int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
