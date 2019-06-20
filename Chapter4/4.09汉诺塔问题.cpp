#include<iostream>
#include <vector>
#include <string>
using namespace std;

void func(int n,string from,string mid,string to)
{
	if(n == 1)
		cout<<"move from "<<from<<" to "<<to<<endl;
	else
	{
		func(n-1,from,to,mid);//将左侧的n-1个盘移到中间 
		func(1,from,mid,to);//将左侧最后一个盘移到最右边 
		func(n-1,mid,from,to);//将中间剩下的盘移到最右边 
	}
}
void hanoi(int n)
{
	if(n > 0)
		func(n,"left","mid","right");
}
int process(vector<int> arr,int i,int from,int mid,int to)
{
	if(i == -1)
		return 0;
	if(arr[i] != from && arr[i] != to)
		return -1;
	if(arr[i] == from)
		return process(arr,i-1,from,to,mid);
	else
	{
		int rest = process(arr,i-1,mid,from,to);
		if(rest == -1)
			return -1;
		return (1<<i) + rest;
	}
}
int step1(vector<int> arr)
{
	if(arr.size() == 0)
		return -1;
	return process(arr,arr.size()-1,1,2,3);
}
int step2(vector<int> arr)
{
	if(arr.size() == 0)
		return -1;
	int from  = 1;
	int mid = 2;
	int to = 3;
	int rest = 0;
	int i = arr.size()-1;
	while(i>=0)
	{
		int tmp;
		if(arr[i] != from && arr[i] != to)
		return -1;
		if(arr[i] == from)
		{
			tmp = to;
			to = mid;
			mid = tmp;
		}
		else
		{
			rest += 1<<i;
			tmp = mid;
			from = mid;
			mid = tmp;
		}
		i--;
		
	}	
	return rest;
}
int main()
{
	int n = 2;
	hanoi(n);
	vector<int> arr = {3,3};
	cout<<step1(arr)<<endl;
	cout<<step2(arr)<<endl;
	return 0;
 } 
