/*
 * Q13_Exterior_of_binary_tree.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Anoshak
 */
/* program for boundary traversal of a binary tree */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left, *right;
};


void printBoundary(struct node* root, vector<int>& curr, vector<int>& last, vector<int>& result)
{
    if(root)
    {
        curr.push_back(root->data);
        if(!root->left && !root->right)
        {
            if(result.size()==0)
                result = curr;
            else result.push_back(root->data);
            last = curr;
        }
        printBoundary(root->left,curr,last,result);
        printBoundary(root->right,curr,last,result);
        curr.pop_back();
    }
}

// A function to do boundary traversal of a given binary tree
void printBoundary (struct node* root)
{
    vector<int> curr;
    vector<int> last;
    vector<int> result;
    printBoundary(root,curr,last,result);
    for(int i=last.size()-2;i>0;i--)
        result.push_back(last[i]);
    for(int val : result)
        cout<<val<<" ";
}

// A utility function to create a node
struct node* newNode( int data )
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

/*// Driver program to test above functions
int main()
{
	// Let us construct the tree given in the above diagram
	struct node *root		 = newNode(20);
	root->left			 = newNode(8);
	root->left->left		 = newNode(4);
	root->left->right		 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right			 = newNode(22);
	root->right->right	 = newNode(25);

	printBoundary( root );

	return 0;
}*/




