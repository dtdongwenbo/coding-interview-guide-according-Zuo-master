#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(vector<int> v,int i,int rest)
{
	if(i == v.size() )
		return rest == 0 ? 0 : -1;
	int res = -1;
	for(int k = 0;k*v[i]<= rest;k++)
	{
		int next = process(v,i+1,rest-k*v[i]);
		if(next != -1)
			res = res == -1 ? (next+k) : min(res,next+k);
	}
	return res;
	
}
int minCoins1(vector<int> v,int aim)
{
	if(v.empty() || aim <0)
		return -1;
	return process(v,0,aim);
}
int minCoins2(vector<int> v,int aim)
{
	if(v.empty() || aim <0)
		return -1;
	int N = v.size();
	vector<vector<int>> dp(N+1,vector<int>(aim+1,0));
	for(int i = 1;i<=aim;i++)
		dp[N][i] = -1;
	for(int i = N-1;i>=0;i--)
	{
		for(int j = 0;j<=aim;j++)
		{
			dp[i][j] = -1;//先把v[i][j]设置成无效
			if(dp[i+1][j] != -1){
				dp[i][j] = dp[i+1][j];
			} 
			if(j-v[i] >=0 && dp[i][j-v[i]] != -1)//不越界且有效
			{
				if(dp[i][j] == -1)
					dp[i][j] = dp[i][j-v[i]]+1;
				else
					dp[i][j] = min(dp[i][j-v[i]]+1,dp[i+1][j]);
			 } 
		}
	}
	return dp[0][aim];
}
int main()
{
	vector<int> v = {5,2,3};
	int aim = 20;
	cout<<"暴力方法："<<minCoins1(v,aim)<<endl;
	cout<<"优化："<<minCoins2(v,aim)<<endl;
}
