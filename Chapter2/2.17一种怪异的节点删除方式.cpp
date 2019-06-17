#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* removeNodeWired(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* next = head->next;
	if(next == NULL)
	{
		cout<<"error"<<endl;
		return NULL;
	}
	head->val = next->val;
	head->next = next->next;
	delete next;
	
}
//�������Ҫ������������һ���ڵ��ֵ�滻��Ҫɾ���Ľڵ㣬��ȱ�����޷�ɾ�����һ���ڵ�
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 8;i> 0;i--)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
		
	}
	p1 = h1->next;
	removeNodeWired(p1->next->next);
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	return 0;
 } 
