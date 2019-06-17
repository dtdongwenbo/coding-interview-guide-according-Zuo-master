#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int maxRecFromBottom(int count[],int len)
{
	if(count == NULL || len <=0)
	return 0;
	int maxArea = 0;
	stack<int> s;
	for(int i = 0;i<len;i++)
	{
		while(!s.empty() && count[i]<= count[s.top()])
		{
			//��ǰ����λ��Ϊi
			//������ջ�����ݱ��Ϊj
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (i - k - 1) * count[j];
			maxArea = max(curArea,maxArea); 
		}
		s.push(i);
	}
	while(!s.empty())
	{
		int j = s.top();
		s.pop();
		int k = s.empty() ? -1 : s.top();
		int i = len;
		int curArea = (i - k -1)*count[j];
		maxArea = max(curArea,maxArea);
	}
	return maxArea;
}
int maxRecsize(int* mat,const int length,const int height)
{
	if(mat == NULL || length<=0 || height<=0)
	return 0;
	int maxArea = 0;
	int *count = new int[length]();//�����������ʵ�ֽ�count������ڴ��ʼ��Ϊ0
	//��int count[length] = {0} ���ڿ��Ա��С��length�ǲ��е� 
	for(int i = 0;i<height;i++)
	{
		for(int j = 0;j<length;j++)
		{
			int num = *(mat+i*length+j);//�˴����ٴ�ע��
			//https://www.cnblogs.com/zl1991/p/4748733.html 
			count[j] = num == 0 ? 0 : count[j] +1;	
			cout<<count[j]<<endl;
		}
		
	 cout<<"----------"<<endl;
	 maxArea = max(maxRecFromBottom(count,length),maxArea);
	}
	return maxArea;
}
int main()
{

    int mat[][4] = {{1,0,1,1},{1,1,1,1},{1,1,1,0}};
    cout << "maxRecSize is : " << maxRecsize(*mat,4,3) << endl;
	
	return 0;
 } 
