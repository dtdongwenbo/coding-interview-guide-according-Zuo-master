#include <iostream>
#include <vector>

using namespace std;

int process1(vector<int> v,int i,int aim)
{
	if(i == v.size())
		return aim == 0 ? 1 : 0;
	int result = 0;
	for(int k = 0;v[i]*k<=aim;k++){
		result += process1(v,i+1,aim-v[i]*k);
	}
	return result;
}
int coins1(vector<int> v,int aim)//暴力搜索 
{
	if(v.empty() || aim<0)
		return 0;
	return process1(v,0,aim);
}
int coins2(vector<int> v,int aim)//优化 
{
	if(v.empty() || aim<0)
		return -1;
	vector< vector<int> > dp(v.size(),vector<int>(aim+1,0));
	for(int i = 0;i<v.size();i++)
		dp[i][0] = 1;
	for(int j = 0;v[0]*j<=aim;j++)
		dp[0][v[0]*j] = 1;
	for(int i = 1;i<v.size();i++)
	{
		for(int j = 1;j<=aim;j++)
		{
			dp[i][j] = dp[i-1][j];
			dp[i][j] += j-v[i]>=0 ? dp[i][j-v[i]] : 0;
		}
	 }
	 return dp[v.size()-1][aim]; 
}
int process2(vector<int> v,int index,int aim,vector<vector<int>> map)
{
	int res = 0;
	if(index == v.size())
		res = aim == 0 ? 1 :0;
	else
	{
		int mapvalue = 0;
		for(int i = 0;v[index]*i<=aim;i++)
		{
			mapvalue = map[index+1][aim-v[index]*i];
			if(mapvalue != 0)
			{
				res += mapvalue == -1 ? 0 : mapvalue;
			}
			else
			{
				res += process2(v,index+1,aim-v[index]*i,map);
			}
		}
	}
	map[index][aim] = res == 0 ? -1 : res;
	return res;
}

int coins3(vector<int> v,int aim)//记忆化搜索的优化方式 
{
	if(v.empty() || aim<0)
		return -1;
	vector<vector<int>> map(v.size() + 1,vector<int>(aim+1,0));
	return process2(v,0,aim,map);
}
int main()
{
	vector<int> v = {5,10,25,1};
	int aim = 15;
	cout<<"暴力搜索："<<coins1(v,aim)<<endl;
	cout<<"优化："<<coins2(v,aim)<<endl;
	cout<<"记忆化搜索："<<coins3(v,aim)<<endl;
}
