/*
 * Q7_kth_node.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Anoshak
 */

#include "common_utils.h"
#define INT_MAX 2147483647

class Solution {
    void kthSmallest(TreeNode* root, int k, int *count,int *ans)
    {
       if(root)
       {
           kthSmallest(root->left,k,count,ans);
           *count += 1;
           if(*count ==k)
           {
               *ans = root->val;
               return;
           }
           if(*ans == INT_MAX)
                kthSmallest(root->right,k,count,ans);
       }

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0,ans=INT_MAX;
        kthSmallest(root,k,&count,&ans);
        return ans;
    }
};



