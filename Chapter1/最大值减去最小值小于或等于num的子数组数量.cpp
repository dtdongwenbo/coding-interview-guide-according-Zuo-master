#include <iostream>
#include <deque>

using namespace std;

int getNum(int arr[],int len,int num)
{
	if(arr == NULL ||len<=0)
	return 0;
	deque<int> qmin;
	deque<int> qmax;
	int i = 0,j = 0,res = 0;
	
	while(i<len)
	{
		while(j<len)
		{
			while(!qmin.empty() && arr[qmin.front()]>=arr[j])
				qmin.pop_front();
			qmin.push_back(j);
			while(!qmax.empty() && arr[qmax.front()]<=arr[j])
				qmax.pop_front();
			qmax.push_back(j);
			cout<<j<<endl;
			if((arr[qmax.front()] - arr[qmin.front()])>num)
				break;
			++j;
			
		}
		
		res = res + j - i;
		if(qmin.front() == i)//若第一个数是最小的 则弹出 
		qmin.pop_front();
		if(qmax.front() == i)
		qmax.pop_front();
		++i;
	}
	return res;
}
int main()
{
	int a[] = {3,2,5,1,4,7,8,6};
	cout << "The number of sub arrays to meet the requirements is: " << getNum(a,8,4)<< endl;
	
	return 0;
}
