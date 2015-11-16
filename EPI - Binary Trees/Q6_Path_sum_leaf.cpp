/*
 * Q6_Path_sum_leaf.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"

class Solution {
private:
    bool hasPathSum(TreeNode* root, int currSum, int targetSum)
    {
        if(root)
        {
            currSum = currSum + root->val;
            if(!root->left && !root->right && currSum == targetSum)
                return true;
            else return (hasPathSum(root->left,currSum,targetSum) || hasPathSum(root->right,currSum,targetSum));
        }
        else return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root,0,sum);
    }
};


