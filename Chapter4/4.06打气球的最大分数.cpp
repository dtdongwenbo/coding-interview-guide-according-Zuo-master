#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int process(vector<int> arr,int L,int R)
{
	if(L == R)
	{
		return arr[L-1]*arr[L]*arr[R+1];
	}
		
	//边界的两种情况
	int maxScore = max(arr[L-1]*arr[L]*arr[R+1]+process(arr,L+1,R),
				 arr[L-1]*arr[R]*arr[R+1] + process(arr,L,R-1));
	//尝试中间气球最后被打爆的每种方案
	for(int i = L+1;i<R;i++)
	{
		maxScore = max(arr[L-1]*arr[i]*arr[R+1] + process(arr,i+1,R)+process(arr,L,i-1),maxScore);		
	 } 
	 return maxScore;
}
int maxCoins1(vector<int> v)
{
	if(v.size() == 0)
		return 0;
	if(v.size() == 1)
		return v[0];
	/*
	简单的说是判断3种情况：
	1.最左边L的最后被打爆；2.最右边的最后被打爆；3.除了两端的某个气球最后被打爆；
	因此需要建立一个辅助数组来处理边界的问题 
	*/
	int N = v.size();
	vector<int> help(N+2,0);
	help[0] = 1;
	help[N+1] = 1;
	for(int i = 0;i<N;i++)
		help[i+1] = v[i];
	return process(help,1,N);
	
}
int maxCoins2(vector<int> v)
{
	if(v.size() == 0)
		return 0;
	if(v.size() == 1)
		return v[0];
	int N = v.size();
	vector<int> help(N+2,0);
	help[0] = 1;
	help[N+1] = 1;
	for(int i = 0;i<N;i++)
		help[i+1] = v[i];
	vector<vector<int>> dp(N+2,vector<int>(N+2,0));
	for(int i = 1;i<=N;i++)
		dp[i][i] = help[i-1]*help[i]*help[i+1];
	for(int L = N;L>=1;L--){
		for(int R = L+1;R<=N;R++)
		{
			//最后打爆左边
			int finalL = help[L-1]*help[L]*help[R+1]+dp[L+1][R];
			//最后打爆右边
			int finalR = help[L-1]*help[R]*help[R+1]+dp[L][R-1];//根据process函数写的
			dp[L][R] = max(finalL,finalR);
			//中间位置打爆的每一种方案
			for(int i = L+1;i<R;i++)
			{
				dp[L][R] = max(dp[L][R],help[L-1]*help[i]*help[R+1]+dp[L][i-1]+dp[i+1][R]);
			}
		}
	}
	return dp[1][N];
}
int main()
{
	vector<int> v = {4,2,3,5,1,6};
	cout<<"暴力搜索："<<maxCoins1(v)<<endl;
	cout<<"动态规划："<<maxCoins2(v)<<endl;
	return 0;
}
