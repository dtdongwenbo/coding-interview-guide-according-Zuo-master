#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int data)
	{
		val = data;
		left = NULL;
		right = NULL; 
	}
};
Node* generate(vector<int> arr,int start,int end)
{
	if(start>end)
		return NULL;
	int mid = (start + end)/2;
	Node* root = new Node(arr[mid]);
	root->left = generate(arr,start,mid-1);
	root->right = generate(arr,mid+1,end);
	return root;
}
Node* generateTree(vector<int> arr)
{
	if(arr.size() == 0)
		return NULL;
	return generate(arr,0,arr.size()-1);
}
void preOrederRecur(Node* head)
{
	if(head == NULL)
		return ;
	
	cout<<head->val<<" ";
	preOrederRecur(head->left);
	preOrederRecur(head->right);
}

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* root = generateTree(arr);
	preOrederRecur(root);
	return 0;
}
