# EE599HW4Q3
For gtest EraseShouldHandleCaseOne, when erase 2, where there is no child of 2, it should erase 2 directly
        
        1
         \
          5
         / \
        3   8
       / \ / \
      2  4 6  10
            \ / \
            7 9 11

        1
         \
          5
         / \
        3   8
         \ / \
         4 6  10
            \ / \
            7 9 11

For gtest EraseShouldHandleCaseTwo, when erase 6, where there is one child, it should work like this:
        
        1
         \
          5
         / \
        3   8
       / \ / \
      2  4 6  10
            \ / \
            7 9 11
        1
         \
          5
         / \
        3   8
       / \ / \
      2  4 7  10
              / \
              9 11

For gtest EraseShouldHandleCaseThree, when erase 5, where there are two children of 5, the 6 should take the place of 5, only in that way can keep the BST in order.
        
        1
         \
          5
         / \
        3   8
       / \ / \
      2  4 6  10
            \ / \
            7 9 11

        1
         \
          6
         / \
        3   8
       / \ / \
      2  4 7  10
              / \
              9 11


>>Run time

Find, Push and Erase has a run time of O(height of the tree), where height of the tree in the best case is logN and worst case N, which N represents the number of input values
