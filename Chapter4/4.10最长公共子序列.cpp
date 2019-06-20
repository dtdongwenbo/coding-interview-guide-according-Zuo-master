#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> getdp(string str1,string str2)
{
	vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;
	for(int i = 1;i<str1.size();i++)
		dp[i][0] = max(dp[i-1][0],str1[i] == str2[0] ? 1 : 0);
	for(int j = 1;j<str2.size();j++)
		dp[0][j] = max(dp[0][j-1],str1[0] == str2[j] ? 1 : 0);
	for(int i = 1;i<str1.size();i++)
	{
		for(int j = 1;j<str2.size();j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(str1[i] == str2[j])
			{
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
	}
	return dp;
}
string lces(string str1,string str2)
{
	if(str1.size() == 0 || str2.size() == 0)
		return NULL;
	vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
	dp = getdp(str1,str2);
	int index = dp[str1.size()-1][str2.size()-1];
	string res(index,'0');//定义字符串的方法 
	int str1len = str1.size() - 1;
	int str2len = str2.size() - 1;
	while(index>=0)
	{
		
		if(str2len>0 && dp[str1len][str2len] == dp[str1len][str2len-1])
			str2len--;
		else if(str1len > 0 && dp[str1len][str2len] == dp[str1len-1][str2len])
			str1len--;
		else 
		{
			res[index--] = str1[str1len];
			str1len--;
			str2len--;
		}
	}
	return res;
}

int main()
{
	string str1 = "1A2C3D4B56";
	string str2 = "B1D23CA45B6A";
	cout<<lces(str1,str2); 
	return 0;
}
