#include <bits/stdc++.h>
# include <vector>
# include <queue>
# include "binarytree.h"
using namespace std;
binarytreenode<int>* takeinput(){
	int a;
	cin>>a;
	queue <binarytreenode<int>*> q;
	
	if(a==-1){
		return NULL;
	}
	
	binarytreenode<int> *root=new binarytreenode<int>(a);
	q.push(root);
	while(q.size()!=0){
		binarytreenode<int> *front=q.front();
		q.pop();
		int c;
		cin>>c;
			if (c!=-1){
				binarytreenode<int> *root1=new binarytreenode<int>(c);
				front->left=root1;
				q.push(root1);
				}
			
			int f;
			cin>>f;
			if (f!=-1){
			
			binarytreenode<int> *root2=new binarytreenode<int>(f);
			front->right=root2;
			q.push(root2);
		}
		
	}
	return root;
}

void preorder(binarytreenode<int> *root,vector <int> &v){
	if(root==NULL){
		return;
	}
	v.push_back(root->data);
	preorder(root->left,v);
	preorder(root->right,v);
	
	return;
}


int main(){
	binarytreenode<int>* root=takeinput();
	int s;
	cin>>s;
	vector <int> v;
	preorder(root, v);
	sort(v.begin(),v.end());
	int a;
	a=v.size();
	int lo=0;
	int hi=a-1;
	while(lo<hi){
		if(v[lo]+v[hi]==s){
			cout<<v[lo]<<" "<<v[hi]<<endl;
			lo++;
			hi--;
			
		}
		else if(v[lo]+v[hi]>s){
			hi--;
		}
		else{
			lo++;
		}
		
	}
	return 0;
	
	
}
