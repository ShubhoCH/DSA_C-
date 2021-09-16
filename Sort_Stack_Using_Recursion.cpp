#include <bits/stdc++.h>
using namespace std;
void INSERT(stack<int>& s, int temp){
	if(s.size() == 0 || s.top()<= temp){
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	INSERT(s,temp);
	s.push(val);
	return;
}
void SORT(stack<int>& s){
	if(s.size() == 1)
		return;
	int temp = s.top();
	s.pop();
	SORT(s);
	INSERT(s,temp);
}
int main()
{
	int n,x;
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s.push(x);
	}
	SORT(s);
	for(int i=0;i<n;i++)
	{
		cout<<s.top();
		s.pop();
	}
}

