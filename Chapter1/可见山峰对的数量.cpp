#include <iostream>
#include <stack>

using namespace std;
int getInternalSum(int k)
{
	return k == 1?0:(k*(k-1)/2);
}
int nextIndex(int i,int size)
{
	return i<(size-1)?(i+1):0;
}
int getVisableNum(int* arr,int length)
{
	if(arr == NULL)
		return 0;
	int size = length;
	int maxIndex = 0;
	//找到最大值得位置
	for(int i = 0;i<size;i++)
		maxIndex = arr[maxIndex]<arr[i] ? i:maxIndex;
	stack<pair<int, int> > s; 
	//先把（最大值，1）这个记录放入stack中；
	s.push(pair<int, int>(arr[maxIndex], 1));
	//从最大值位置的下一位置沿next方向遍历
	int index;
	if(maxIndex == length - 1)
		index = 0;
	else 
		index = maxIndex +1;
	int res = 0;
	while(index != maxIndex)
	{
		//当数字arr[index]要进栈，判断会不会破坏单调栈的规则，如果破坏了，则需计算山峰对的数量
		while(s.top().first < arr[index])
		{
			int k = s.top().second;
			s.pop();
			//弹出记录为（x,k），如果k=1，产生2对，如果k>=2，则残生2*k+C(2,k)对 
			res += getInternalSum(k)+2*k;
		}
		//当前数字入栈
		if(s.top().first == arr[index]) 
			s.top().second++;
		else 
			s.push(pair<int, int>(arr[index], 1));
		index = nextIndex(index,size);
	 } 
	 cout<<res<<endl;
	 //第一阶段清算
	 while(s.size()>2)
	 {
	 	int times = s.top().second;
	 	s.pop();
	 	res += getInternalSum(times)+2*times;
	  } 
	  cout<<res<<endl;
	//第二阶段清算
	while (s.size()==2)
	{
		int times = s.top().second;
	 	s.pop();
	 	res += getInternalSum(times)+(s.top().second == 1 ? times : 2*times);
	} 
	cout<<res<<endl;
	//第三阶段清算
	int times = s.top().second;
	s.pop();
	res +=  getInternalSum(times);
	return res;
}
int main()
{
	int arr[11] = {5,4,3,5,4,2,4,4,5,3,2};
	cout<<getVisableNum(arr,11)<<endl;
	return 0;
}
