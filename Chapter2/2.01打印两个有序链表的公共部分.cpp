#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x):
		val(x),next(NULL){
		}
}; 
void PrintCommon(ListNode* h1,ListNode* h2)
{
	while(h1 != NULL && h2 != NULL)
	{
		if(h1->val<h2->val)
			h1 = h1->next;
		else if(h1->val > h2->val)
			h2 = h2->next;
		else 
		{
			cout<<h1->val<<" ";
			h1 = h1->next;
			h2 = h2->next;
		}
	}
}
int main()
{
	ListNode* h1,*h2;
	ListNode* p1= (ListNode *)malloc(sizeof(ListNode));
	ListNode* p2= (ListNode *)malloc(sizeof(ListNode));
	h1 = p1;
	h2 = p2;
	for(int i = 0;i<10;i++)
	{
		ListNode* n = (ListNode *)malloc(sizeof(ListNode));
		n->val = i;
		h1->next = n;
		h1 = n;
		n->next = NULL;
	}
	h1 = p1->next;
	for(int i = 5;i<9;i++)
	{
		ListNode* n = (ListNode *)malloc(sizeof(ListNode));
		n->val = i;
		h2->next = n;
		h2 = n;
		n->next = NULL;
	}
	h2 = p2->next;
	PrintCommon(h1,h2);
	return 0;

}
