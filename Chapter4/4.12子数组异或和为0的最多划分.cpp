#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int mostEOR(vector<int> arr)
{
	if(arr.size() == 0)
		return 0;
	unordered_map<int,int> map;
	int eor = arr[0];//这里有点奇怪 书上是0 但是好像arr[0]对一点 结果都是一样的 
	map[0] = -1;
	vector<int> dp(arr.size(), 0);
	dp[0] = arr[0] == 0 ? 1 : 0;
	map[arr[0]] = 0;
	for(int i = 1;i<arr.size();i++)
	{
		eor ^= arr[i];
		if(map.find(eor) != map.end())
		{
			int preEorIndex = map[eor];
			dp[i] = preEorIndex == -1 ? 1 : (dp[preEorIndex] + 1);
		}
		dp[i] = max(dp[i-1],dp[i]);
		map[eor] = i;
	}
	return dp[arr.size() - 1];
}
int main()
{
	vector<int> arr = {3,2,1,9,0,7,0,2,1,3};
	cout<<mostEOR(arr)<<endl;
	vector<int> v = {1,2,3,1,2,3,1,2,3};
    cout << mostEOR(v) << endl;
    v = {1,2,3,4,5,6,7,8,9,10};
    cout << mostEOR(v) << endl;
    v = { 1,2,3,4,5,6,7,8,9,10,11 };
    cout << mostEOR(v) << endl;
	return 0;
}
