#include<bits/stdc++.h>
using namespace std;
int FindSubset(string s, string substr, int ans){
	if(s.length() == 0){
		ans++;
		if(substr == "")
			cout<<"Blank Sub-String ";
		else
			cout<<substr<<" ";
		return ans;
	}
	ans = FindSubset(s.substr(1), substr + s[0], ans);
	ans = FindSubset(s.substr(1), substr, ans);
	return ans;
}
int main()
{
	string s, substr = ""; 
	int ans;
	while(true){
		ans = 0;
		cin>>s;
		ans = FindSubset(s, substr, ans);
		cout<<"\nTotal: "<<ans<<endl;
	} 
}

