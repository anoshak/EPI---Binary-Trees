/*
 * Q3_LCA.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"

class Solution {
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool* p_visited, bool* q_visited)
    {
        if(!root)
            return NULL;
        if(root == p)
        {
            *p_visited = true;
            return p;
        }
        if(root == q)
        {
            *q_visited = true;
            return q;
        }
        TreeNode* left_lca = lowestCommonAncestor(root->left,p,q,p_visited,q_visited);
        TreeNode* right_lca = lowestCommonAncestor(root->right,p,q,p_visited,q_visited);
        if(left_lca && right_lca)
            return root;
        else if(left_lca)
            return left_lca;
        else return right_lca;
    }
    bool search(TreeNode* root, TreeNode* p)
    {
        if(!root || !p)
            return false;
        if(root == p)
             return true;
        else return (search(root->left,p) || search(root->right,p));
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool p1 = false, p2 = false;
        TreeNode* lca = lowestCommonAncestor(root,p,q,&p1,&p2);
        if(p1&&p2 || p1 && search(root,q) || p2 && search(root,p))
            return lca;
        else return NULL;
    }
};


