/*
 * common_utils.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Anoshak
 */
#include "common_utils.h"

void print_vector_matrix(vector<vector<int> >& arr)
{
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void print_vector(vector<int>& arr)
{
	for(unsigned i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void swap (vector<int>& arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int stoi(string s)
{
	if(s.size()==0)
		return 0;
	int i=0,answer=0;
	bool neg = false;
	if(s[i] == '-')
	{
		neg = true;
		i++;
	}
	for(;i<s.size();i++)
	{
		answer = answer*10 + (s[i]-'0');
	}
	if(neg)
		return answer*-1;
	else return answer;
}

