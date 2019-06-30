#include <iostream>
#include <string>

using namespace std;

bool isUnique1(string str)
{
	if(str.empty())
		return false;
	bool map[256];//”√bool
	for(int i = 0;i<str.size();i++)
	{
		if(map[str[i]])
			return false;
		map[str[i]] = true;
	 } 
	 return true;
}
int main()
 {
 	string str1 = "abc";
 	string str2 = "121";
 	cout<<isUnique1(str1)<<endl;
 	cout<<isUnique1(str2)<<endl;
 }
