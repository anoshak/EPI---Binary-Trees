/*
 * Q9_Inorder_traversal_given_parent.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"

struct Node {
	int val;
	Node* left, *right, *parent;
};

vector<int> inorder(Node* root) {
	vector<int> result;
	Node* prev=NULL,*curr=root,*next;
	while(curr)
	{
		if(prev == curr->parent)
		{
			//Going down
			if(curr->left)
			{
				next = curr->left;
			}
			else
			{
				result.push_back(curr->val);
				next = curr->right? curr->right : curr->parent;
			}
		}
		else if (prev == curr->left)
		{
			//left subtree done. go to right
			result.push_back(curr->val);
			next = curr->right ? curr->right : curr->parent;
		}
		else
		{
			//both subtrees done; Go up
			next = curr->parent;
		}
		prev = curr;
		curr = next;
	}
	return result;
}

