/*
 * Q2_Symmetric_tree.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */


#include "common_utils.h"

class Solution {
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(root1 && root2)
        {
            if(root1->val == root2->val && isSymmetric(root1->right,root2->left) && isSymmetric(root2->left,root1->right))
            {
                return true;
            }
            else return false;
        }
        else if(!root1 && !root2)
            return true;
        else return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);
    }
};



