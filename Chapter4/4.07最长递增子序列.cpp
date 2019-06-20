#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getdp1(vector<int> arr)
{
	/*
	������������еķ�����
	��ͷ��β����Ѱ����߱��Լ�С���ҵ�������������λ�ã����ҵ�����
	�ڵ��������г����ϼ�1����δ�ҵ�������Ϊ1 
	*/ 
	vector<int> dp(arr.size(),0);
	for(int i = 0;i<arr.size();i++)
	{
		dp[i] = 1;
		for(int j = 0;j<i;j++)
		{
			if(arr[i]>arr[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	return dp;
}
vector<int> getdp2(vector<int> arr)
{
	//���ö��ֲ������Ż��ٶȣ�endsΪ��¼��Ч����rightΪ��Ч���ķ�Χ
	vector<int> dp(arr.size(),0);
	vector<int> ends(arr.size(),0);
	int right = 0;
	ends[0] = arr[0]; 
	dp[0] = 1;
	int l = 0;
	int r = 0;
	int m = 0;
	for(int i = 1;i<arr.size();i++)
	{
		l = 0;
		r = right;
		while(l<=r)
		{
			m = (l+r)/2;
			if(arr[i]>ends[m])
				l = m+1;
			else 
				r = m-1;
		}
		right = max(right,l);
		ends[l] = arr[i];
		dp[i] = l+1;//��������г���=ends��Ч�����ȼ�1 

	}
	return dp;
}
vector<int> generateLIS(vector<int> arr,vector<int> dp)
{
	
	int len = 0;
	int index = 0;
	for(int i = 0;i<dp.size();i++)
	{
		if(dp[i]>len)
		{
			len = dp[i];
			index = i;
		}
		
	}
	vector<int> lis(arr.size(),0);
	lis[--len] = arr[index];

	for(int i = index;i>=0;i--)
	{
		if(arr[i]<arr[index] && dp[i] == dp[index] - 1)
		{
			lis[--len] = arr[i];
			index = i;
		}
		
	}
	return lis;
}
vector<int> lis1(vector<int> arr)
{
	if(arr.size() == 0)
		return vector<int>();;
	vector<int> dp =getdp1(arr);
	return generateLIS(arr,dp);

 } 
 vector<int> lis2(vector<int> arr)
{
	if(arr.size() == 0)
		return vector<int>();;
	vector<int> dp =getdp2(arr);

	return generateLIS(arr,dp);

 } 
int main()
{
	vector<int> arr= {2,1,5,3,6,4,8,9,7};
	vector<int> res = lis1(arr);
	vector<int> res2 = lis2(arr);
	int i = 0;
	 while(res[i]!=NULL)
	 {
	 	cout<<res[i]<<" ";
	 	i++;
	 }
	 cout<<endl;
	 i = 0;
	 while(res2[i]!=NULL)
	 {
	 	cout<<res2[i]<<" ";
	 	i++;
	 }
	return 0;
}
