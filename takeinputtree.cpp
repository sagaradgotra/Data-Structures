# include <iostream>
# include <queue>
# include "treenode.h"
using namespace std;
treenode<int>* takeinput(){
	int a;
	cout<<"Enter rootnumber:"<<endl;
	cin>>a;
	treenode<int> *root=new treenode<int>(a);
	queue<treenode<int>*> q;
	q.push(root);
	while(q.size()!=0){
	treenode<int> *front=q.front();
	q.pop();
	int b;
	cout<<"Enter number of child of"<<front->data<<endl;
	cin>>b;
	for(int i=0;i<b;i++){
		int d;
		cout<<"Enter the"<<i<<"th child of"<< front->data<<endl;
		cin>>d;
		treenode<int> *child=new treenode<int>(d);
		front->children.push_back(child);
		q.push(child);		
	}
	
	
}

		return root;
	
}

void print(treenode<int> *root){
	queue <treenode<int>*> q1;
	q1.push(root);
	while(q1.size()!=0){
		treenode<int>* front=q1.front();
		q1.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++){
			cout<<front->children[i]->data<<",";
			q1.push(front->children[i]);
		}
		cout<<""<<endl;
		
		
	}
	return;
}

int countnode(treenode<int> *root){
	if (root==NULL){
		return;
	}
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=countnode(root->children[i]);
	}
	return ans;
}

int countsum(treenode<int> *root){
	
	int ans=root->data;
	for(int i=0;i<root->children.size();i++){
		ans+=countsum(root->children[i]);
	}
	return ans;
}

	
	
	

int main(){
	/*
	treenode<int>* root=new treenode<int>(10);
	treenode<int>* root1=new treenode<int>(20);
	treenode<int>* root2=new treenode(30);
	root->children.push_back(root1);
	root->children.push_back(root2);
	*/
	treenode<int> *node= takeinput();
	print(node);
	int p;
	p=countnode(node);
	cout<<p<<endl;
	int f;
	f=countsum(node);
	cout<<f<<endl;
	
	return 0;
	
}
