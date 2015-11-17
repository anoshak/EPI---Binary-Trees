/*
 * Q8_Inorder_successor_given_parent.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */


#include "common_utils.h"

struct Node
{
	int val;
	Node* left,*right,*parent;
};

Node* inorderSuccessor(Node* p)
{
	if(!p)
		return NULL;
	if(p->right)
	{
		while(p->left)
			p=p->left;
		return p;
	}
	else
	{
		Node* par = p->parent;
		while(par && par->right==p)
		{
			p= par;
			par =p->parent;
		}
		return par;
	}
}


