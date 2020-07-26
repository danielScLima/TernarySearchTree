// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ternarysearchtree.h"

TEST_CASE( "Testing the insert call in the tree", "[single-file]" )
{
	TernarySearchTree r;
	NodeOfTernarySearchTree *root = r.getRoot();
	REQUIRE(root == nullptr);
	
	r.insert("home");
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle == nullptr);
	
	r.insert("homeless");
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	r.insert("love");
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->right->data == 'l');
	REQUIRE(!root->right->isTheLast);
	
	REQUIRE(root->right->middle->data == 'o');
	REQUIRE(!root->right->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->data == 'v');
	REQUIRE(!root->right->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->data == 'e');
	REQUIRE(root->right->middle->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->middle == nullptr);
	
	r.insert("hi");
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->right->data == 'l');
	REQUIRE(!root->right->isTheLast);
	
	REQUIRE(root->right->middle->data == 'o');
	REQUIRE(!root->right->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->data == 'v');
	REQUIRE(!root->right->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->data == 'e');
	REQUIRE(root->right->middle->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->middle->left->data == 'i');
	REQUIRE(root->middle->left->isTheLast);
	
	REQUIRE(root->middle->left->middle == nullptr);
}

TEST_CASE( "Testing the remove call in the tree", "[single-file]" )
{
	TernarySearchTree r;
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	NodeOfTernarySearchTree *root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->right->data == 'l');
	REQUIRE(!root->right->isTheLast);
	
	REQUIRE(root->right->middle->data == 'o');
	REQUIRE(!root->right->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->data == 'v');
	REQUIRE(!root->right->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->data == 'e');
	REQUIRE(root->right->middle->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->middle->left->data == 'i');
	REQUIRE(root->middle->left->isTheLast);
	
	REQUIRE(root->middle->left->middle == nullptr);
	
	REQUIRE(r.remove("hi"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	REQUIRE(root->right->data == 'l');
	REQUIRE(!root->right->isTheLast);
	
	REQUIRE(root->right->middle->data == 'o');
	REQUIRE(!root->right->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->data == 'v');
	REQUIRE(!root->right->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->data == 'e');
	REQUIRE(root->right->middle->middle->middle->isTheLast);
	
	REQUIRE(root->right->middle->middle->middle->middle == nullptr);
	
	REQUIRE(r.remove("love"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);
	
	REQUIRE(r.remove("home"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 'h');
	REQUIRE(!root->isTheLast);
	
	REQUIRE(root->middle->data == 'o');
	REQUIRE(!root->middle->isTheLast);
	
	REQUIRE(root->middle->middle->data == 'm');
	REQUIRE(!root->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->data == 'l');
	REQUIRE(!root->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->data == 'e');
	REQUIRE(!root->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(!root->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->data == 's');
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->isTheLast);
	
	REQUIRE(root->middle->middle->middle->middle->middle->middle->middle->middle == nullptr);

	REQUIRE(r.remove("homeless"));
	
	root = r.getRoot();
	REQUIRE(root == nullptr);
}

TEST_CASE( "Testing the search call in the tree", "[single-file]" )
{
	TernarySearchTree r;
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") != nullptr);
	REQUIRE(r.search("hi") != nullptr);
}

TEST_CASE( "Testing the search and remove calls in the tree", "[single-file]" )
{
	TernarySearchTree r;
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") != nullptr);
	REQUIRE(r.search("hi") != nullptr);
	
	REQUIRE(r.remove("love"));
	REQUIRE(r.remove("hi"));
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") == nullptr);
	REQUIRE(r.search("hi") == nullptr);
}

TEST_CASE( "Testing the insert of duplicated entries in the tree", "[single-file]" )
{
	TernarySearchTree r;
	
	REQUIRE(r.insert("home"));
	REQUIRE(r.insert("homeless"));
	REQUIRE(r.insert("love"));
	REQUIRE(r.insert("hi"));
	
	REQUIRE(!r.insert("home"));
	REQUIRE(!r.insert("homeless"));
	REQUIRE(!r.insert("love"));
	REQUIRE(!r.insert("hi"));
}

