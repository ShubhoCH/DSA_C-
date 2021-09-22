#include <iostream>
#include <stack>
using namespace std;
stack<int> solve(stack<int> &s, int index, bool even){
	if(index==1)
	{
		s.pop();
		if(!even)
			return s;
		solve(s,index,false);
	}
	else{
		int temp = s.top();
		s.pop();
		solve(s,index-1, even);
		s.push(temp);
	}
	return s;
}
int main(){
	stack<int> s;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		s.push(x);
	}
	if(n%2==0)
		solve(s, n/2, n%2==0);
	else
		solve(s, n/2 + 1, n%2==0);
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
