#include <iostream>
#include <string>
using namespace std;
int FindMaxLengthOfSubString(string s)
{
	int i1 = s.find("a");
	if(i1==-1)
		return -1;
	for(int i=s.length()-1;i>i1;i--)
		if(s[i] == 'z')
			return i - i1 + 1;
	
	return -1;
}
int main(){
	string s;
	cin>>s;
	cout<<FindMaxLengthOfSubString(s);
}
