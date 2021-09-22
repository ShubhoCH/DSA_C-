#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int ele){
	if(s.empty()){
		s.push(ele);
		return;
	}
	int temp = s.top();
	s.pop();
	solve(s,ele);
	s.push(temp);
	return;
}
void reverse(stack<int> &s){
	if(s.size() == 1)
		return;
	int temp = s.top();
	s.pop();
	reverse(s);
	solve(s,temp);
	return;
}
int main(){
	stack<int> s;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		s.push(x);
	}
	cout<<s.top()<<endl;
	reverse(s);
	cout<<s.top()<<endl;
	for(int i=0;i<n;i++){
		cout<<s.top();
		s.pop();
	}
}
