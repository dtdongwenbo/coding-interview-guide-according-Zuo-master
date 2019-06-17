#include <iostream>
#include<stdlib.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x):
		val(x),next(NULL){
		}
};
int getLive(int count,int m)
{
	if(count == 1)
	return 1;
	return (getLive(count-1,m) + m -1)%count +1;
	
}
ListNode* josephKill(ListNode* head,int m)
{
	if(head == NULL || head->next == head || m<1)
		return head;
	ListNode *cur = head ->next;
	int count = 1;
	while(cur!= head)
	{
		count++;
		cur = cur->next;
	}
	int live = getLive(count,m);
	
	ListNode* dst = NULL;
	for(int i = 1;i<=count;i++)
	{
		if(live == i)
			dst = head;
		head = head->next;
	}
	
	return dst;
	
}
int main()
{
	int m = 3;//报数到m删除
	
	ListNode* p1;
	ListNode* h1 = (ListNode *)malloc(sizeof(ListNode));
	p1 = h1;
	ListNode* n;
	for(int i = 1;i<6;i++)
	{
		n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	n->next = h1->next;
	p1 = h1->next;
	ListNode* dst2;
	dst2 = josephKill(p1,m);
	cout<<"留下来的节点："<<dst2->val<<endl;
	return 0;
	
}
