#include <iostream>
#include <vector> 
#include<algorithm>
#include <stdlib.h>
using namespace std;

bool cmp1(const vector<int> &a, const vector<int> &b)
{
	if (a[0] == b[0])
		return a[1] > b[1]; 
	else
    	return a[0] < b[0];
}
int maxEnvelope(vector<vector<int>> matrix)
{
	/*
	�Ƚ����Ȱ��մ�С�����˳�������������sort����ʵ��
	Ȼ�����ȵ�����������м��ɵõ��� 
	*/
	vector<int> end(matrix.size(),0);
	end[0] = matrix[0][1];
	int right = 0;
	int r = 0;
	int l = 0;
	int m = 0;
	for(int i = 1;i<matrix.size();i++)
	{
		l = 0;
		r = right;
		while(l<=r)
		{
			m = (l+r)/2;
			if(matrix[i][1]>end[m])
				l = m+1;
			else 
				r = m-1;
		}
		right = max(right,l);

		end[l] = matrix[i][1];
	}
	return right + 1;//��Ч��Ϊ0-right���󳤶����1 
}
int main()
{
	vector<vector<int>> v(9,vector<int>(9,0));
	v = {{3,4},{2,3},{4,5},{1,3},{2,2},{3,6},{1,2},{3,2},{2,4}};
	sort(v.begin(), v.end(),cmp1);//Ĭ��Ϊ��С��������
	cout<<maxEnvelope(v);
	return 0; 
}
