/*
 * Q5_Sum_root_to_leaf_paths.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"

class Solution {
void sumNumbers(TreeNode* root, int currSum, int* totalSum)
{
    if(root)
    {
        currSum = currSum*10 + root->val;
        if(!root->left && !root->right)
        {
            *totalSum += currSum;
        }
        else
        {
            sumNumbers(root->left,currSum,totalSum);
            sumNumbers(root->right,currSum,totalSum);
        }
    }
}
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0, currSum = 0;
        sumNumbers(root,currSum,&totalSum);
        return totalSum;
    }
};


