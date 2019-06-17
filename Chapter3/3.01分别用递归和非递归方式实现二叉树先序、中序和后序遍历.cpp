#include<iostream>
#include <stdlib.h>
#include <stack>

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
//�ݹ�ǰ�����
void preOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
	
 } 
 //�ݹ�ǰ�����
 void preOrederUnRecur(Node* head)
 {
 	if(head != NULL)
 	{
 		stack<Node*> s;
 		s.push(head);
 		while(!s.empty())
 		{
 			head = s.top();
 			s.pop();
 			cout<<head->val<<" ";
 			//�˴��Ƚ��Ҷ��� 
 			if(head->right != NULL)
 				s.push(head->right);
 			if(head->left != NULL)
 				s.push(head->left);
		 }
	 }
	 cout<<endl;
 }
 //�ݹ��������
void inOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	inOrderRecur(head->left);
	cout<<head->val<<" ";
	inOrderRecur(head->right);
	
 } 
//�ǵݹ��������
void inOrderUnRecur(Node* head)
{
	if(head != NULL)
	{
		stack<Node*> s;
		while(!s.empty() || head != NULL)
		{
			if(head != NULL)
			{
				s.push(head);
				head = head->left;
			}
			else
			{
				head = s.top();
				s.pop();
				cout<<head->val<<" ";
				head = head->right;
			}
		}
	}
	cout<<endl;
}
 //�ݹ�������
void posOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout<<head->val<<" ";	
 } 
//�ݹ�������(����ջ�� 
void posOrderUnRecur1(Node* head)
{
	if(head != NULL)
	{
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(head);
		while(!s1.empty())
		{
			head = s1.top();
			s1.pop();
			s2.push(head);
			if(head->left != NULL)
				s1.push(head->left);
			if(head->right != NULL)
				s1.push(head->right);
			
		}
		while(!s2.empty())
		{
			head = s2.top();
			s2.pop();
			cout<<head->val<<" ";
		}
	}
	cout<<endl;
}
//�ݹ�������(����ջ�� 
void posOrderUnRecur2(Node* head)
{
	if(head != NULL)
	{
		stack<Node*> s;
		s.push(head);
		Node* c = NULL;
		Node* h = head;
		while(!s.empty())
		{
			c = s.top();
			if(c->left != NULL &&h != c->left && h != c->right)
			{
				s.push(c->left);
			}
			else if(c->right != NULL && h != c->right)
			{
				s.push(c->right);
			}
			else
			{
				cout<<s.top()->val<<" ";
				s.pop();
				h = c;  
			}
		}
	}
	cout<<endl;
}
//�����鹹����ȫ������
void createBT(Node** head,int arr[],int len,int index = 0)
{
	if(index > len -1)
		return ;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left),arr,len,2*index+1);
	createBT(&((*head)->right),arr,len,2*index+2);
 } 
 int main()
 {
 	int arr[] = {1,2,3,4,5,6,7,8,9};
 	Node *head = NULL;
 	createBT(&head,arr,9);
 	cout<<"�ݹ�ǰ���������� ";
 	preOrderRecur(head);
 	cout<<endl;
 	cout<<"�ǵݹ�ǰ����������";
 	preOrederUnRecur(head);
 	cout<<endl;
	cout<<"�ݹ������������� "; 
	inOrderRecur(head); 
 	cout<<endl;
 	cout<<"�ǵݹ�������������"; 
	inOrderUnRecur(head); 
 	cout<<endl;
 	cout<<"�ݹ������������"; 
 	posOrderRecur(head);
	cout<<endl;
	cout<<"�ǵݹ����������(����ջ)��"; 
	posOrderUnRecur1(head);
	cout<<endl;
	cout<<"�ǵݹ����������(һ��ջ)��"; 
	posOrderUnRecur2(head);
	cout<<endl;
 	return 0;
 	
 }
