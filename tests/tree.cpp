#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
	tree_t<int> tree;
	REQUIRE( tree.root() == nullptr );
}

TEST_CASE("insert and print tree")
{
	std::string input1{
		"        ---- 9\n"
		"            ---- 8\n"
		"    ---- 7\n"
		"        ---- 6\n"
		"---- 5\n"
		"    ---- 4\n"
		"        ----3\n"};
	std::string input2{
		"                ---- 9\n"
		"            ---- 8\n"
		"        ---- 7\n"
		"            ---- 6\n"
		"    ---- 5\n"
		"        ---- 4\n"
		"---- 3\n"
		"            ---- 1\n"
		"        ---- 0\n"
		"            ---- -1\n"
		"    ---- -2\n"
		"            ---- -3\n"
		"        ---- -4\n"
		"                ---- -5\n"
		"            ---- -6\n"
		"                ---- -7\n"};
	
	tree_t<int> tree1 { 5, 7, 4, 6, 9, 7, 8, 3, 4 };
	tree_t<int> tree2 {0, 1, -1, 3, -2, 4, 5, 6, 7, 8, 9, -3, -4, -5, -6, -7, -5};
	
	std::ostringstream ostream1;
	std::ostringstream ostream2;
	
	tree1.print(ostream1);
	tree2.print(ostream2);
	REQUIRE( input1 == ostream1.str() );
	REQUIRE( input2 == ostream2.str() );
}

TEST_CASE("find tree")
{
	tree_t<int> tree;
	
	tree.insert(5);
	tree.insert(7);
	tree.insert(4);
	
	REQUIRE( tree.find(5) == true );
	REQUIRE( tree.find(7) == true );
	REQUIRE( tree.find(0) == false );
}

TEST_CASE("compare tree")
{
	tree_t<int> A { 5, 7, 4 };
	tree_t<int> B { 5, 7, 4, 4 };
	tree_t<int> C { 5, 7, 4, 4, 6 };
	
	REQUIRE( (A == B) == true );
	REQUIRE( (C == B) == false );
}

TEST_CASE("isEmpty tree")
{
	tree_t<int> tree1;
	tree_t<int> tree2;
	
	tree1.insert(5);
	tree1.insert(7);
	tree1.insert(4);
	
	REQUIRE( tree1.isEmpty() == false );
	REQUIRE( tree2.isEmpty() == true );
}
