#include <iostream>
#include <stdlib.h> 
#include <stack>
using namespace std;
 struct ListNode{
 	int val;
 	struct ListNode*(next);
 	ListNode(int x):
 		val(x),next(NULL){
		 }
 };
 ListNode* reverse(ListNode* head)
 {
 	ListNode* pre = NULL;
 	ListNode* next = NULL;
 	while(head != NULL)
 	{
 		next = head ->next;
 		head->next = pre;
 		pre = head;
 		head = next;
 		
	 }
	 return pre;
 }
 ListNode* addList1(ListNode* l1,ListNode* l2)
 {
 	stack<int> s1;
 	stack<int> s2;
 	while(l1 != NULL)
 	{
 		s1.push(l1->val);
 		l1 = l1->next;
	 }
	 while(l2 != NULL)
	 {
	 	s2.push(l2->val);
	 	l2 = l2->next;
	 }
	 int num1 = 0,num2 = 0,num = 0,c = 0;
	 ListNode* p1;
	 ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	 p1 = h1;
	 while(!s1.empty() || !s2.empty())
	 {
	 	
	 	if(s1.empty())
	 	{
	 		num1 = 0;
		 }
		 else
		 {
		 	num1 = s1.top();
		 	s1.pop();
		 }
		if(s2.empty())
		{
			num2 = 0;
		}
		else
		{
			num2 = s2.top();
			s2.pop();
		}
	 	num = num1 + num2 + c;
	 	c = num / 10;
	 	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	 	n -> val = num%10;
	 	p1->next = n;
	 	p1 = n;
	 	n->next = NULL;	
	 }
	 if(c == 1)
	 {
	 	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	 	n->val = 1;
	 	p1->next = n;
	 	p1 = n;
	 	n->next = NULL;
	 }
	 p1 = h1 ->next;
	 p1 = reverse(p1);
	 return p1;
 }
 ListNode* addList2 (ListNode* l1,ListNode* l2)
 {
 	l1 = reverse(l1);
 	l2 = reverse(l2);
 	ListNode* p1 = l1;
 	ListNode* p2 = l2;
 	ListNode* pre = NULL;
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	pre = node;
 	int c = 0;
 	int sum1 = 0,sum2 = 0, sum = 0;

 	while(p1 != NULL || p2 != NULL)
 	{
 		sum1 = p1 != NULL ? p1->val :0;
		sum2 = p2 != NULL ? p2->val :0;
		sum = sum1 + sum2 + c;

		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = sum%10;
		pre->next = n;
		pre = n;
		n->next = NULL;
		c = sum/10;
		p1 = p1 != NULL ? p1->next : NULL;
		p2 = p2 != NULL ? p2->next : NULL;
		
	 }

	 if(c == 1)
	 {
	 	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	 	n->val = 1;
	 	pre->next = n;
	 	pre = n;
	 	n->next = NULL;
	 }
	l1 = reverse(l1);
 	l2 = reverse(l2);
 	node = reverse(node->next);
 	return node;
 	
 }
 int main()
 {
 	ListNode* p1;
 	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
 	p1 = h1;
 	ListNode* p2;
 	ListNode* h2 = (ListNode*)malloc(sizeof(ListNode));
 	p2 = h2;
	int add1[] = {9,3,7};
 	int add2[] = {6,3};
 	for(int i = 0;i<3;i++)
 	{
 		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
 		n->val = add1[i];
 		p1->next = n;
 		p1 = n;
 		n->next = NULL;
 		
	}
	for(int i = 0;i<2;i++)
 	{
 		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
 		n->val = add2[i];
 		p2->next = n;
 		p2 = n;
 		n->next = NULL;		
	}
	p1 = h1->next;
	p2 = h2->next;
	
	ListNode* a2;
	a2 = addList1(p1,p2);
	cout<<"翻转法的计算结果：";
	while(a2 != NULL)
	{
		cout<<a2->val;
		a2= a2->next;
	}
	return 0;
	
 }
