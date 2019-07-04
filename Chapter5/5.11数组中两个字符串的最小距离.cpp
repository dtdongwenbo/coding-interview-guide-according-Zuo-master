#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int minDistance(string* strs,string str1,string str2,int len)
{
	if(str1.empty() || str2.empty() || strs == NULL)
		return -1;
	if(str1 == str2)
		return 0;
	int last1 = -1;
	int last2 = -1;
	int m = INT_MAX;
	for(int i = 0;i < len;i++)
	{
		if(strs[i] == str1){
			m = min(m,last2 == -1 ? m : i-last2);
			last1 = i;
		}
		if(strs[i] == str2){
			m = min(m,last1 == -1 ? m : i-last1);
			last2 = i;
		}
	}
	return m == INT_MAX ? -1 : m;
}
int main()
{
	string strs1[7] = {"1","3","3","3","2","3","1"};
	string str11 = "1";
	string str21 = "2";
	string strs2[1] = "CD";
	string str12 = "CD";
	string str22 = "AB";
	cout<<minDistance(strs1,str11,str21,7)<<endl;
	cout<<minDistance(strs2,str12,str22,1)<<endl;
	return 0;
}
