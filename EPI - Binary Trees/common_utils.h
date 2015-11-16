/*
 * common_utils.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Anoshak
 */

#ifndef COMMON_UTILS_H_
#define COMMON_UTILS_H_

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<climits>
#include<stdlib.h>
#include<time.h>
#include<cctype>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

void print_vector(vector<int>& arr);
void print_vector_matrix(vector<vector<int> >& arr);
void swap (vector<int>& arr, int i, int j);
int stoi(string s);

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 };

#endif /* COMMON_UTILS_H_ */
