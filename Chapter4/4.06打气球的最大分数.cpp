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
		
	//�߽���������
	int maxScore = max(arr[L-1]*arr[L]*arr[R+1]+process(arr,L+1,R),
				 arr[L-1]*arr[R]*arr[R+1] + process(arr,L,R-1));
	//�����м�������󱻴򱬵�ÿ�ַ���
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
	�򵥵�˵���ж�3�������
	1.�����L����󱻴򱬣�2.���ұߵ���󱻴򱬣�3.�������˵�ĳ��������󱻴򱬣�
	�����Ҫ����һ����������������߽������ 
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
			//�������
			int finalL = help[L-1]*help[L]*help[R+1]+dp[L+1][R];
			//�����ұ�
			int finalR = help[L-1]*help[R]*help[R+1]+dp[L][R-1];//����process����д��
			dp[L][R] = max(finalL,finalR);
			//�м�λ�ô򱬵�ÿһ�ַ���
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
	cout<<"����������"<<maxCoins1(v)<<endl;
	cout<<"��̬�滮��"<<maxCoins2(v)<<endl;
	return 0;
}
