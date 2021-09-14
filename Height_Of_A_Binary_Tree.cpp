#include<iostream>
using namespace std;
class Node{
	public:
		Node* left;
		Node* right;
		int data;
};
Node* CreateNewNode(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
Node* AddNode(Node* root, int data){
	if(root == NULL)
	{
		root = CreateNewNode(data);
		return root;
	}
	if(data > root->data)
		root->right = AddNode(root->right, data);
	else
		root->left = AddNode(root->left, data);
	return root;
}
void PrintNode(Node* root){
	if(root == NULL)
		return;
	cout<< root->data<<"  ";
	PrintNode(root->left);
	PrintNode(root->right);	
}
int CountHeight(Node* root, int ans){
	if(root == NULL)
	{
		return ans;
	}	
	int left = CountHeight(root->left, ans+1);
	int right = CountHeight(root->right, ans+1);
	return max(left, right);
}
int main()
{
	Node* root = NULL;
	int n,data;
	cin>>n;
/*	int arr[6] = {5,3,2,6,4,1};
	root = CreateNewNode(arr[0]);
	root->left = CreateNewNode(arr[1]);
	root->left->left = CreateNewNode(arr[2]);
	root->right = CreateNewNode(arr[3]);
	root->left->right = CreateNewNode(arr[4]);
	root->left->left->left = CreateNewNode(arr[5]);*/
	for(int i =0 ;i<n;i++){
		cin>>data;
		root = AddNode(root, data);
	}
	cout<<"Pre-Order Tree: ";
	PrintNode(root);
	// Print the Height of the Binary Tree:
	cout<<endl<<"Height of Tree: "<<CountHeight(root, 0);
}

