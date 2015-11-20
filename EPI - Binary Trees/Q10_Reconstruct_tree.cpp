/*
 * Q10_Reconstruct_tree.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"



class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, map<int,int>& mymap, int ps, int pe, int is, int ie)
    {
        if(is>ie || ps > pe)
            return NULL;
        int idx = mymap[preorder[ps]];
        TreeNode* newNode = new TreeNode(preorder[ps]);
        newNode->left = buildTree(preorder,inorder,mymap,ps+1,ps+idx-is,is,idx-1);
        newNode->right = buildTree(preorder,inorder,mymap,ps+idx-is + 1,pe,idx+1,ie);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size()!=preorder.size())
            return NULL;
        //make hash map of inorder elements and index
        map<int,int> mymap;
        for(int i=0;i<inorder.size();i++)
        {
            mymap[inorder[i]] = i;
        }

        return buildTree(preorder,inorder,mymap,0,preorder.size()-1,0,inorder.size());
    }
};


