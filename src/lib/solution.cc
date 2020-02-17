#include "solution.h"

BST::BST(std::vector<int> initial_values)
{
  for(auto x : initial_values)
  push(root_, x);
}

void BST::push(TreeNode* &node_ptr,int key)
{
  if(node_ptr == nullptr)
  node_ptr = new TreeNode(key);
  else if (key > node_ptr->val)
  return push(node_ptr->right, key);
  else if (key < node_ptr->val)
  return push(node_ptr->left, key);
}

bool BST::find(TreeNode* node_ptr, int key)
{
  if(node_ptr == nullptr)
  return false;
  else
  {
    if(node_ptr->val == key)
    return true;
    else if(node_ptr->val > key)
    return find(node_ptr->left, key);
    else if(node_ptr->val < key)
    return find(node_ptr->right, key);
  }
}

bool BST::erase(int key)
{
  TreeNode * node_ptr = root_;
  TreeNode * parent_node_ptr = root_;
  if(find(root_, key))
  {

    while (node_ptr->val != key)
    {

      if(node_ptr->val > key)
      {
        parent_node_ptr = node_ptr;
        node_ptr = node_ptr->left;
      }
      else if(node_ptr->val < key)
      {
        parent_node_ptr = node_ptr;
        node_ptr = node_ptr->right;
      }

    }

    if(node_ptr->left == nullptr && node_ptr->right == nullptr)//the deleted node has no child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = nullptr;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = nullptr;
    }
    else if(node_ptr->left == nullptr && node_ptr->right != nullptr)//the deleted node only has a right child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = node_ptr->right;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = node_ptr->right;
    }
    else if(node_ptr->left != nullptr && node_ptr->right == nullptr)//the deleted node only has a left child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = node_ptr->left;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = node_ptr->left;
    }
    else//the deleted node has two children. Let's find the minimum value of its right subtree, the node wiht minimum value must have no or only one child. This child must be a right child.
    {
      TreeNode * min_val_ptr = node_ptr->right;
      TreeNode * min_parent_ptr = node_ptr->right;
      while(min_val_ptr->left != nullptr)
      {
        min_parent_ptr = min_val_ptr;
        min_val_ptr = min_val_ptr->left;
      }
      
      node_ptr->val = min_val_ptr->val;

      min_parent_ptr->left = min_val_ptr->right;//no matter min_val_ptr->right is nullptr or not
    }
    return true;
  }
  else
  {
    return false;
  }
  

}