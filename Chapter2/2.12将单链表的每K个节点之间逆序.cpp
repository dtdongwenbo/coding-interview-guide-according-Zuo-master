#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* resign1(stack<ListNode*> &s, ListNode *left,ListNode* right)
{
	ListNode* cur = s.top();
	s.pop();
	if(left != NULL)
		left->next = cur;
	ListNode *next = NULL;
	while(!s.empty())
	{
		next = s.top();
		s.pop();
		cur->next = next;
		cur = next;
	 } 
	 cur->next = right;
	 return cur;
}
ListNode* reverseKNodes1(ListNode *head,int k)
{
	if(k<2)
		return head;
	stack<ListNode*> s;
	ListNode* newhead = head;
	ListNode* cur = head;
	ListNode* pre = NULL;
	ListNode* next = NULL;
	while(cur != NULL)
	{
		next = cur->next;
		s.push(cur);
		if(s.size() == k)
		{
			pre = resign1(s,pre,next);
			newhead = newhead == head ? cur : newhead;
			
		}
		cur = next;

	}
	return newhead;
}
void resign2(ListNode *left,ListNode *start,ListNode *end,ListNode *right)
{
	ListNode *pre = start;
	ListNode* cur = start->next;
	ListNode* next = NULL;
	while(cur != right)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	if(left != NULL)
		left->next = end;
	start->next = right;
	
}
ListNode* reverseKNodes2(ListNode *head,int k)
{
	if(k<2)
		return head;
	ListNode* cur = head;
	ListNode* start = NULL;
	ListNode* pre = NULL;
	ListNode* next = NULL;
	int count = 1;
	while(cur != NULL)
	{
		next = cur->next;
		while(count == k)
		{
			start = pre == NULL ? head : pre->next;
			head = pre == NULL ? cur : head;
		
			resign2(pre,start,cur,next);
			pre = start;
			count = 0;
		}
		count++;
		cur = next;
	}
	return head;
	
}

int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	int k= 3;
	p1 = h1;
	for(int i = 1;i<9;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	p1 = reverseKNodes2(p1,k);
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1= p1->next;
	}

	return 0;
	
	
 } 
