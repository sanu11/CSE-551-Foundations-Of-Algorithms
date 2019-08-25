#include<bits/stdc++.h>
using namespace std;
class node;
int n;
int *a;
node *root;
class node{
public:
	int value;
	node *left;
	node *right;
	node(int value){
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
static void inorder(node * temp){
	if(temp==NULL)
		return;
	cout<<temp->value<<" ";
	inorder(temp->left);
	inorder(temp->right);

}

static node* construct(){

	queue<node*>list;
	node *temp,*leftNode,*rightNode,*parent;
	for(int i=0;i<n;i++){
		cin>>a[i];
		temp = new node(a[i]);
		list.push(temp);
	}	
	// cout<<list.size()<<endl;
	//for odd size;
	int last,mx,flag=0;
	int size;
	while(list.size()!=1){

		size =list.size();
		flag=0;
		//if even list no change.
		//for odd list last element should be popped and added to the last.Thus dont iterate over the last.
		if(size%2==0)
			last=size-1;
		else{
			last=size-2;
			flag=1;
		}

		for(int i=0;i<last;i++){
			
			// pop 2 elemnents
			leftNode = list.front();
			list.pop();
			rightNode = list.front();
			list.pop();

			//push max of 2.
			mx = max(leftNode->value,rightNode->value);
			parent=new node(mx);
			parent->left = leftNode;
			parent->right = rightNode;
			list.push(parent);	
			i++;
		}
		if(flag){
			temp = list.front();
			list.pop();
			list.push(temp);
		}
		// cout<<list.size()<<endl;

	}
	return list.front();


}

static void recur(node *temp,int *mx,int rootVal){

	if(temp->left==NULL&&temp->right==NULL)
		return;
	node *leftNode,*rightNode;
	leftNode = temp->left;	
	rightNode = temp->right;
	if(leftNode->value==rootVal){
		*mx = max(*mx,rightNode->value);
		recur(leftNode,mx,rootVal);
	}
	else if(rightNode->value==rootVal){
		*mx = max(*mx,leftNode->value);
		recur(rightNode,mx,rootVal);
	}
	else
		return;


}

static int findSecMax(){
	int mx = -1;
	node::recur(root,&mx,root->value);
	return mx;
}
};

int main(){

	cin>>n;
	a= new int[n];

	root = node::construct();
	int value  = node::findSecMax();

	cout<<"Best Player: "<<root->value<<endl; 
	cout<<"Second Best Player: "<<value<<endl;

	return 0;
}