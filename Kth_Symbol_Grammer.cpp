#include <bits/stdc++.h>
using namespace std;
int solve(int n, int k){
	if(n==1 && k == 1)
		return 0;
	if( k <= pow(2,n-1)/2 )
		return solve(n-1,k);
	else
		return !solve(n-1, k - pow(2,n-1)/2 );
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<solve(n,k);
}
