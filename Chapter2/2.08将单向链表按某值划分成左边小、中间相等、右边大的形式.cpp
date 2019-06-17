#include <iostream>
#include <stdlib.h> 
using namespace std;

struct ListNode{
	int val;
	struct ListNode*(next);

};
void swap(ListNode *a,ListNode *b)
{
	int tmp = a->val;
	a->val = b->val;
	b->val = tmp;
}
 
//快排中的分区方法 
void arrPartition(ListNode* arr,int len,int pivot)
{
	int index = 0;
	len--;
	while(index <len)
	{
		while(index<len && arr[index].val<= pivot)
		index++;
		swap(&arr[index],&arr[len]);
		while(index<len&&arr[len].val>= pivot)
		len--;
		swap(&arr[index],&arr[len]);
	}
}
//进阶算法
ListNode* listPartition2(ListNode *head,int pivot)
{
	ListNode* sH = NULL;//小的头 
	ListNode* sT = NULL;
	ListNode* eH = NULL;
	ListNode* eT = NULL;
	ListNode* bH = NULL;
	ListNode* bT = NULL;
	ListNode* next = NULL;//保存下个节点
	while(head != NULL){
		next = head->next;
		head ->next = NULL;
		if(head->val < pivot){
			if(sH == NULL)
			{
				sH = head;
				sT = head;
			}
			else
			{
				sT->next = head;
				sT = head;
			}
		}
		else if(head->val == pivot){
			if(eH == NULL){
				eH = head;
				eT = head;
			}
			else
			{
				eT->next = head;
				eT = head;
			}
		}
		else if(head->val > pivot){
			if(bH== NULL){
				bH = head;
				bT = head;
			}
			else
			{
				bT->next = head;
				bT = head;
			}
		}
		head = next;
		
	} 
	if(sT != NULL)
	{
		sT->next = eH;
		eT = eT == NULL ? sT : eT;
	}
	if(eT != NULL)
	{
		eT->next = bH;
		bT = bT == NULL ? eT : bT;
	}
	return sH != NULL ? sH : eH != NULL ? eH : bH;
}
 // 
ListNode* listPartition1(ListNode *head,int pivot)
{
	if(head == NULL)
		return head;
	ListNode* cur = head;
	int len = 0;
	
	while(cur != NULL)
	{
		++len;
		cur = cur->next;		
	}
	
	ListNode *arr = new ListNode[len];

	cur = head;
	for(int i= 0;i<len;i++)
	{
		arr[i] = *cur;
		cur = cur->next;
		
	}
	arrPartition(arr,len,pivot);
	for(int i =1;i<len;i++)
	{
		arr[i-1].next = &arr[i];
	}
	arr[len-1].next = NULL;
	return &arr[0];
	
}
int main()
{
	int arr[] = {9,0,4,5,1};
	int pivot = 3;
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 0;i<5;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = arr[i];
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;

	p1 = listPartition2(p1,pivot);
	
	for(int i = 0;i<5;i++)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	return 0;
}
