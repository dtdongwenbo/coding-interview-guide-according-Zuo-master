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
//本题的主要方法是利用下一个节点的值替换需要删除的节点，其缺点是无法删除最后一个节点
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
