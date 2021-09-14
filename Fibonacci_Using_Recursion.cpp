#include<iostream>
using namespace std;
int Fibo(int n){
	if(n<0)
		cout<<"Enter a Valid Number!\n";
	if(n==0)
		return 0;
	if(n<2)
		return 1;
	return Fibo(n-1) + Fibo(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<Fibo(n);
}

