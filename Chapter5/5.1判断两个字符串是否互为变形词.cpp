#include<iostream>
#include <string>
#include <vector>
using namespace std;

bool isDeformation(string str1,string str2)
{
	if(str1.size() == 0 || str2.size() == 0)
		return false;
	vector<int> map(256,0);
	for(int i = 0;i<str1.size();i++)
	{
		map[str1[i]]++;
	}
		
	for(int i = 0;i<str2.size();i++)
	{
		if(map[str2[i]]-- == 0)
		{
			return false;
		}
			
	}	
	return true;
}
int main()
{
	string str1 = "123";
	string str2 = "231";
	string str3 = "2331";
	if(isDeformation(str1,str2))
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl; 
	if(isDeformation(str1,str3))
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl; 
	return 0;
 } 
