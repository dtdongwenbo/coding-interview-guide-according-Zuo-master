#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int data){
		val = data;
		left = NULL;
		right = NULL;
	}
};
void createBT(Node** head,int arr[],int len,int index = 0)
{
	if(index > len-1 || arr[index] == -1)
		return ;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left),arr,len,2*index+1);
	createBT(&((*head)->right),arr,len,2*index+2);
}
void preOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
	
 }
 void printTree(Node* root,int height,string to,int len)
 {
 	if(root == NULL)
 		return ;
 	printTree(root->right,height+1,"v",len);
 	//
 	stringstream s;
 	s<<root->val;
 	string printvalue = to+s.str()+to;
 	int lenM = printvalue.length();
 	int lenL = (len-lenM)/2;
 	int lenR = len - lenM - lenL;
 	printvalue = string(lenL,' ') + printvalue + string(lenR,' ');//打空格方法 
 	cout<<string(height*len,' ')<<printvalue<<endl;
 	//
 	printTree(root->left,height+1,"^",len);
 	
 	
  } 
int main()
{
	int arr[] = {1,2,3,4,-1,5,6,-1,7};
	Node* root = NULL;
	createBT(&root,arr,9);
	//preOrderRecur(root);
	cout<<"Binary Tree"<<endl;
	printTree(root,0,"H",17);
	return 0;

}
