#include <iostream>
#include <deque>
using namespace std;

int* getMaxWindow(int arr[],int len,int w)
{
	if(arr == NULL || w<1 || len<w)
		return NULL;
	deque<int> qmax;
	int* res = new int;//…Ë÷√÷∏’Î 
	int index = 0;
	for(int i = 0;i<len;i++)
	{
		while(!qmax.empty()&&arr[qmax.back()]<=arr[i])
			qmax.pop_back();
		qmax.push_back(i);
		if(qmax.front() == i-w)
			qmax.pop_front();
		if(i>=w-1)
			res[index++] = arr[qmax.front()];
	}
	return res;
	
}
int main()
{
	int arr[] = {4,3,5,4,3,3,6,7};
    int *res = getMaxWindow(arr,8,3);
    for(int i=0;i<6;i++)
        cout << res[i] << endl;
    return 0;
}
