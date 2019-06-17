#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

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
void createBT(Node** head,int arr[],int len, int index = 0)
{
	if(index > len-1 || arr[index] == -1)
		return ;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left),arr,len,2*index+1);
	createBT(&((*head)->right),arr,len,2*index + 2);
}
//ǰ����������Ĺ����Ƿ���ȷ
void preOrderRecur(Node* head)
{
	if(head == NULL)
	return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
 } 
 /*
 ������׼һ��

����1��ͷ�ڵ�Ϊ�߽�ڵ㣻

����2��Ҷ�ڵ�Ϊ�߽�ڵ㣻

����3������ڵ��������ڵĲ���������������ҵģ���ôҲ�Ǳ߽�ڵ㡣
 */
 int getHeight(Node* root,int l)
 {
 	if(root == NULL)
 		return l;
 	return max(getHeight(root->left,l+1),getHeight(root->right,l+1));
 }
 void setEdgeMap(Node* root,Node* edgeMap[][2],int l)
 {
 	if(root == NULL)
 		return ;
 	edgeMap[l][0] = edgeMap[l][0] == NULL ? root : edgeMap[l][0];//��һ�б�����߽� 
 	edgeMap[l][1] = root;//�ڶ��б����ұ߽�
	setEdgeMap(root->left,edgeMap,l+1);
	setEdgeMap(root->right,edgeMap,l+1); 
	
 }
 void printLeafNotInMap(Node* root,Node* edgeMap[][2],int l)
 {
 	if(root == NULL)
 		return ;
 	if(root->left == NULL && root->right == NULL && root != edgeMap[l][0] && root != edgeMap[l][1])
 		cout<<root->val<<" ";
 	printLeafNotInMap(root->left,edgeMap,l+1);
 	printLeafNotInMap(root->right,edgeMap,l+1);
 }
void printEdge1(Node* root)
{
	if(root == NULL)
		return ;
	int height = getHeight(root,0);
	Node* edgeMap[height][2];
	//memset(edgeMap,0,height*2*sizeof(Node*));//��edgeMap��ص��ڴ�ռ���0
	for(int i = 0;i<height;i++)
	{
		edgeMap[i][0] = 0;
		edgeMap[i][1] = 0;
	}
	setEdgeMap(root,edgeMap,0);//������߽���б߽磬�˴���һ��Ϊ������߽磬�ڶ���Ϊ�����б߽�
	cout<<"��׼һ��";
	for(int i = 0;i<height;i++)//��ӡ��߽� 
		cout<<edgeMap[i][0]->val<<" ";
	printLeafNotInMap(root,edgeMap,0);//��ӡ�Ȳ������ұ߽�Ҳ��������߽��Ҷ�ӽڵ�
	
	for(int i = height-1;i>=0;i--)
	{
		if(edgeMap[i][0] != edgeMap[i][1])
		cout<<edgeMap[i][1]->val<<" ";//��ӡ�ұ߽�	
	}	
	cout<<endl;
}
/*
������׼����

����1��ͷ�ڵ�Ϊ�߽�ڵ㣻

����2��Ҷ�ڵ�Ϊ�߽�ڵ㣻

����3������߽�������ȥ��·��Ϊ�߽�ڵ㣻

����4�����ұ߽�������ȥ��·��Ϊ�߽�ڵ㡣
*/
void printLeftEdge(Node* root,bool print)
{
	if(root == NULL)
		return ;
	if(print || (root->left == NULL && root->right == NULL))
	{
		cout<<root->val<<" ";
	}
	printLeftEdge(root->left,print);
	printLeftEdge(root->right,print&&(root->left == NULL ? true : false));//���ýڵ��Ѿ�����ӡ������ڵ�Ϊ�գ����ӡ���ҽڵ� 
}
void printRightEdge(Node* root,bool print)
{
	if(root == NULL)
		return ;
	//�˴���Ҫע�⣬���ڴ�ӡ���Ҫ����ʱ�룬����Ҫ���ж������ж��Ҳ��ܺ���߽������� 
	printRightEdge(root->left,print&&(root->right == NULL ? true : false));
	printRightEdge(root->right,print);
	if(print || (root->left == NULL && root->right == NULL))
	{
		cout<<root->val<<" ";
	}
}
void printEdge2(Node* root)
{
	if(root == NULL)
		return ;
	cout<<root->val<<" ";
	if(root->left != NULL && root->right != NULL)
	{
		printLeftEdge(root->left,true);
		printRightEdge(root->right,true);
	 } 
	 else
	 {
	 	printEdge2(root->left == NULL ? root->right : root->left);
	 }
	 cout<<endl;
}
int main()
{
	int arr[63] = {1,2,3,-1,4,5,6,-1,-1,7,8,9,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,14,15,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	Node* root = NULL;
	createBT(&root,arr,63);
	//preOrderRecur(root);
	///
	printEdge2(root);
	
}
