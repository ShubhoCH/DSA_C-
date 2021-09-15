#include<iostream>
#include <vector>
using namespace std;
void INSERT(vector<int>& v, int temp){
	if(v.size() == 0 || v[v.size() - 1] <= temp){
		v.push_back(temp);
		return;
	}
	int val = v[v.size() - 1];
	v.pop_back();
	INSERT(v,temp);
	v.push_back(val);
	return;
}
void SORT(vector<int>& v){
	if(v.size() == 1)
		return;
	int temp = v[v.size() - 1];
	v.pop_back();
	SORT(v);
	INSERT(v,temp);
}
int main()
{
	int n,x;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	SORT(v);
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
}

