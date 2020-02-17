#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(PushShould, Insert) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  mytree.push(mytree.root_,12);
  int actual = mytree.root_->right->right->right->right->right->val;
  int expected = 12;
  EXPECT_EQ(expected, actual);
}

TEST(FindShould, ReturnTrue) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  bool actual = mytree.find(mytree.root_,10);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}
TEST(FindShould, ReturnFalse) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  bool actual = mytree.find(mytree.root_,22);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(EraseShould, HandleCaseOne) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  int before_actual = mytree.root_->right->left->left->val;
  int before_expected = 2;
  bool actual = mytree.erase(2);
  bool expected = true;
  TreeNode *after_actual = mytree.root_->right->left->left;
  TreeNode *after_expected = nullptr;
  EXPECT_EQ(expected, actual);//boolean actual indicates success of deleting
  EXPECT_EQ(before_expected, before_actual);//interger before_actual indicates there was a 2
  EXPECT_EQ(after_expected, after_actual);//pointer after_actual indicates where stored a interger 2 had became a hole now
}

TEST(EraseShould, HandleCaseTwo) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  int before_actual = mytree.root_->right->right->left->val;
  int before_expected = 6;
  bool actual = mytree.erase(6);
  bool expected = true;
  int after_actual = mytree.root_->right->right->left->val;
  int after_expected = 7;
  EXPECT_EQ(expected, actual);//boolean actual indicates success of deleting
  EXPECT_EQ(before_expected, before_actual);//interger before_actual indicates there was a 6
  EXPECT_EQ(after_expected, after_actual);//interger after_actual indicates that 7 has took the place of 6
}

TEST(EraseShould, HandleCaseThree) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  int before_actual = mytree.root_->right->val;
  int before_expected = 5;
  bool actual = mytree.erase(5);
  bool expected = true;
  int after_actual = mytree.root_->right->val;
  int after_expected = 6;
  int after_actual_2 = mytree.root_->right->right->left->val;
  int after_expected_2 = 7;
  EXPECT_EQ(expected, actual);//boolean actual indicates success of deleting
  EXPECT_EQ(before_expected, before_actual);//interger before_actual indicates there was a 5
  EXPECT_EQ(after_expected, after_actual);//interger after_actual indicates that 6 has took the place of 5
  EXPECT_EQ(after_expected_2, after_actual_2);//interger after_actual_2 indicates that 7 has took the place of 6
}

