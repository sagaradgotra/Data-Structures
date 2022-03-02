# include <iostream>
# include "treenode.h"
# include <queue>
using namespace std;
treenode<int>* takeinput(){
	int a;
	cin>>a;
	treenode<int> *root=new treenode<int>(a);
	queue <treenode<int>*> q;
	q.push(root);
	int height=1;
	while(q.size()!=0){
		
		treenode<int> *front=q.front();
		q.pop();
		int b;
		cin>>b;
		if(b!=0){
			height++;
		}
	for(int i=0;i<b;i++){
		int c;
		cin>>c;
		treenode<int> *child=new treenode<int>(c);
		front->children.push_back(child);
		q.push(child);
		
		
		
		
		
	}
	
}
		//cout<<height<<endl;
		return root;
	
	
}


bool identical(treenode<int> *root1,treenode<int> *root2){
	if (root1==NULL and root2==NULL){
		return true;}
	if (root1->data!=root2->data){
		return false;
	}
	if (root1->children.size()!=root2->children.size()){
		return false;
	}
	else{
		for (int i=0;i<root1->children.size();i++){
			if(identical(root1->children[i],root2->children[i])==false){
				return false;
				
			}
			
		}
		return true;
	}
}

int nextlarger(treenode<int> *root,int element){
	int ans=NULL;
	if (root->data>element){
		ans=root->data;
	}
	for(int i=0;i<root->children.size();i++){
		int a=nextlarger(root->children[i],element);
		if (ans==NULL){
			ans=a;
		}
		else if (a<ans){
			ans=a;
		}
	}
	return ans;
	
}
/*
int secondlargest(treenode<int> *root){
	int ans=NULL;
	if (root->data>element){
		ans=root->data;
	}
	for(int i=0;i<root->children.size();i++){
		int a=secondlargest(root->children[i]);
		int b=
		if (ans==NULL){
			ans=a;
		}
		else if (a<ans){
			ans=ana;
		}
		else if (a>ans){
			ans=a;
		}
	}
	
	
	
}
*/

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


void replace(treenode<int> *root){
	queue <treenode<int>*> q;
	q.push(root);
	int j=0;
	root->data=j;
	j++;
	while (q.size()!=0){
		treenode<int> *front=q.front();
	
		q.pop();
		for(int i=0;i<front->children.size();i++){
			front->children[i]->data=j;
			q.push(front->children[i]);
			
		}
		if ( front->children.size()==0){
			continue;
		}
		else{
			if (front->data=j-1){
				continue;
			}
			else{
				j++;
			}
			
		}
		
	}
	return;
	
}



int main(){
	/*
	treenode<int> *root1=takeinput();
	treenode<int> *root2=takeinput();
	
	cout<<identical(root1,root2)<<endl;
	*/
	
	treenode<int> *root1=takeinput();
	/*int z;
	cin>>z;
	*/
	replace(root1);
	print(root1);
	
	return 0;
}
