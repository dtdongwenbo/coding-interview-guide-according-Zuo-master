#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* removeListNode1(ListNode* head,int num)
{
	stack<ListNode> s;
	while(head != NULL)
	{
		if(head->val != num)
		{
			s.push(*head);

		}
		head = head->next;
		
	}
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1=  h1;
	while(!s.empty())
	{	
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = s.top().val;
		s.pop();
		p1->next = n;
		p1 = n;
		n->next = NULL;	
		
	}
	p1 = h1->next;
	ListNode* pre = NULL;
	ListNode* next = NULL;
	while(p1)
	{
		next = p1->next;
		p1->next = pre;
		pre = p1;
		p1 = next; 
	}

	return pre;
}
ListNode* removeListNode2(ListNode* head,int num)
{
	while(head != NULL)
	{
		if(head->val != num)
		break;
		head = head->next;
	}
	ListNode* cur = head;
	ListNode* pre = head;
	while(cur != NULL)
	{
		if(cur->val == num)
		{
			pre->next = cur->next;
		}
		else
		{
			pre = cur;
		}
		cur = cur->next;
	}
	return head;
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	int deletenum = 2;
	p1 = h1;
	for(int i = 1;i<7;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	cout<<"初始化的链表：";
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1= p1->next;
	}
	p1 = h1->next;
	p1 = removeListNode1(p1,deletenum);
	cout<<endl;
	cout<<"删除后的链表：";
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1= p1->next;
	}
	return 0;
	
	
 } 
