/*
 * Q14_Connect_right_siblings.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Anoshak
 */
#include "common_utils.h"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	//For a perfect binary tree- Iterative solution with 0(n) time O(1) space;
public:
    void connect(TreeLinkNode* root)
    {
        if(!root)
            return;
        root->next = NULL;
        while(root)
        {
            TreeLinkNode* temp = root;
            while(temp)
            {
                if(temp->left)
                    temp->left->next = temp->right;
                if(temp->right)
                    temp->right->next = temp->next? temp->next->left : NULL;
                temp = temp->next;
            }
            root = root->left;
        }
    }
};

class Solution2 {
	//For any binary tree- Iterative solution with 0(n) time O(1) space;
private:
    TreeLinkNode* getNextRight(TreeLinkNode* p)
    {
        p = p->next;
        while(p)
        {
            if(p->left)
                return p->left;
            if(p->right)
                return p->right;
            p = p->next;
        }
        return NULL;
    }
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        root->next = NULL;
        while(root)
        {
            TreeLinkNode* temp = root;
            while(temp)
            {
                if(temp->left)
                {
                    if(temp->right)
                        temp->left->next = temp->right;
                    else temp->left->next = getNextRight(temp);
                }
                if(temp->right)
                    temp->right->next = getNextRight(temp);
                temp = temp->next;
            }
            if(root->left)
                root=root->left;
            else if(root->right)
                root=root->right;
            else root = getNextRight(root);
        }
        return;

    }
};
