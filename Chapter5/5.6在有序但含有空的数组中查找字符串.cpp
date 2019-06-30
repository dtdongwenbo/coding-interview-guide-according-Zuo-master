#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
核心是使用尽可能的使用二分查找来提高查找的效率 
*/
int getIndex(vector<string> v, string str)
{
	if(v.empty() || str.empty())
		return -1;
	int left = 0;
	int right = v.size() - 1;
	int res = -1;
	int mid = 0;
	int i = 0;
	while(left<=right)
	{
		mid = (right + left)/2;
		if(!v[mid].empty())
		{
			if(v[mid] == str)
			{
				res = mid;
				right = mid - 1;
			}
			else if(v[mid] < str)
			{
				left = mid + 1;	
			}
			else 
			{
				right = mid - 1;
				}	
		}
		else 
		{
			i = mid;
			while(v[i].empty() && --i >= left);
			if(i<left || v[i]<str)
				left = mid +1;
			else 
			{
				res = mid;
				right = i - 1;
			}
		}	
	 } 
	 return res;
}
int main()
{
	vector<string> v = { string(),"a", string(), "a", string(),"b", string(), "c" };
	string str = "a";
	cout<<getIndex(v,"a");
	return 0;
 } 
