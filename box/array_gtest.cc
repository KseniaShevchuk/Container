#include "array_iter.h"
#include "gtest/gtest.h"

TEST(ArrayTest, Creation){
	Array p = array_create(10);
	EXPECT_TRUE(p != NULL);
	
}

TEST(ArrayTest, Size){
	Array p = array_create(10);
	EXPECT_TRUE(p != NULL);
	EXPECT_EQ(0, array_size(p));
}

TEST(ArrayTest, Insert){
	Array p = array_create(10);
	array_insert_last(p, "one");	
	array_insert_last(p, "two");
	EXPECT_EQ(2, array_size(p));
}

TEST(ArrayTest, Get_k){
	Array p = array_create(1);
	const char * one = "one";
	const char * two = "two";
	array_insert_last(p, one);
	EXPECT_EQ(one, array_get_k(p, 0));
	EXPECT_EQ(1, array_size(p));

	array_insert_last(p, two);
	EXPECT_EQ(two, array_get_k(p, 1));
	EXPECT_EQ(2, array_size(p));
	//EXPECT_EQ("two", array_get_k(p, 2));

}

TEST(ArrayTest, InsertAdv){
	Array p = array_create(10);
	const char * one = "one";
	const char * two = "two";
	const char * three = "three";
	array_insert_last(p, one);	
	array_insert_k(p, 1, two);
	EXPECT_EQ(2, array_size(p));
	EXPECT_EQ(two, array_get_k(p, 1));

	array_insert_k(p, 1, three);
	EXPECT_EQ(3, array_size(p));
}
