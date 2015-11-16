/*
 * Q1_Balanced_tree.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"

class Solution {
private:
    bool isBalanced(TreeNode* root, int* height)
    {
        if(root==NULL)
        {
            *height = 0;
            return true;
        }
        else
        {
            int left_height, right_height;
            bool left_bal = isBalanced(root->left,&left_height);
            if(left_bal)
            {
                bool right_bal = isBalanced(root->right,&right_height);
                if(right_bal && abs(left_height - right_height) <2)
                {
                    *height = max (left_height,right_height) + 1;
                    return true;
                }
            }
            return false;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced(root,&height);
    }
};


