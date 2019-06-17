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
	//�ҵ����ֵ��λ��
	for(int i = 0;i<size;i++)
		maxIndex = arr[maxIndex]<arr[i] ? i:maxIndex;
	stack<pair<int, int> > s; 
	//�Ȱѣ����ֵ��1�������¼����stack�У�
	s.push(pair<int, int>(arr[maxIndex], 1));
	//�����ֵλ�õ���һλ����next�������
	int index;
	if(maxIndex == length - 1)
		index = 0;
	else 
		index = maxIndex +1;
	int res = 0;
	while(index != maxIndex)
	{
		//������arr[index]Ҫ��ջ���жϻ᲻���ƻ�����ջ�Ĺ�������ƻ��ˣ��������ɽ��Ե�����
		while(s.top().first < arr[index])
		{
			int k = s.top().second;
			s.pop();
			//������¼Ϊ��x,k�������k=1������2�ԣ����k>=2�������2*k+C(2,k)�� 
			res += getInternalSum(k)+2*k;
		}
		//��ǰ������ջ
		if(s.top().first == arr[index]) 
			s.top().second++;
		else 
			s.push(pair<int, int>(arr[index], 1));
		index = nextIndex(index,size);
	 } 
	 cout<<res<<endl;
	 //��һ�׶�����
	 while(s.size()>2)
	 {
	 	int times = s.top().second;
	 	s.pop();
	 	res += getInternalSum(times)+2*times;
	  } 
	  cout<<res<<endl;
	//�ڶ��׶�����
	while (s.size()==2)
	{
		int times = s.top().second;
	 	s.pop();
	 	res += getInternalSum(times)+(s.top().second == 1 ? times : 2*times);
	} 
	cout<<res<<endl;
	//�����׶�����
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
