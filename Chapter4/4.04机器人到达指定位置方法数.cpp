#include <iostream>
#include <vector> 
using namespace std;

/*
N:λ��1-N;
cur(M):��ǰλ��;
rest(K):ʣ�ಽ��;
P:����Ŀ��λ�� 
*/
int walk(int N,int cur,int rest,int P){
	if(rest == 0)
		return cur == P ? 1 : 0;
	if(cur == 1)
		return walk(N,2,rest-1,P);
	if(cur == N)
		return walk(N,N-1,rest-1,P);
	//������2-n-1��λ���ϣ��������ߵ������Ҫ����
	return walk(N,cur-1,rest-1,P) + walk(N,cur+1,rest-1,P);	
}
int ways1(int N,int M,int K,int P)
{
	//��Ч��������0
	if(N<2 || K<1 || M>N || P<1 || P>N)
		return 0;
	return walk(N,M,K,P); 
}
int ways2(int N,int M,int K,int P)
{
	if(N<2 || K<1 || M>N || P<1 || P>N)
		return 0;
	vector< vector<int> > v(K+1,vector<int>(N+1,0));
	v[0][P] = 1;
	for(int i = 1;i<=K;i++)
	{
		for(int j = 1;j<=N;j++)
		{
			if(j == 1)
				v[i][j] = v[i-1][j+1];
			else if(j == N)
				v[i][j] = v[i-1][j-1];
			else 
			{
				v[i][j] = v[i-1][j-1] + v[i-1][j+1];
				}	
		}
	}
	return v[K][M];
	
}
int ways3(int N,int M,int K,int P)
{
	if(N<2 || K<1 || M>N || P<1 || P>N)
		return 0;
	vector<int> v(N+1,0);
	v[P] = 1;
	for(int i = 1;i<=K;i++)
	{
		int left = v[1];//���Ͻǵ�ֵ 
		for(int j = 1;j<=N;j++)
		{
			int tmp = v[j];
			if(j == 1)
				v[j] = v[j+1];
			else if(j == N)
				v[j] = left;
			else 
			{
				v[j] = v[j+1] + left;
			}
			left = tmp;
		}
	}
	return v[M];
}
int main(){
	int N = 7, M = 4,K = 9, P = 5;
	cout<<"����һ��"<<ways1(N,M,K,P)<<endl;
	cout<<"��������"<<ways2(N,M,K,P)<<endl;
	cout<<"�������Ż���"<<ways3(N,M,K,P)<<endl;
	return 0;
}
