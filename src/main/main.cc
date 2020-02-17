#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
    BST mytree(vect);
    mytree.erase(2);
    std::cout << mytree.root_->right->left->right->val;
    //bool mybool = mytree.find(mytree.root_, 3);
    //std::cout << mybool;
    return EXIT_SUCCESS;
}