# include <iostream>
using namespace std;
class pair{
	public:
	int data;
	int sum;
	pair(int element){
		this->data=element;
		this->sum=element;
	}
};

pair* maxsum(treenode<int> *root){
	int ans;
	ans=root->data;
	pair *p=new pair(ans);
	for(int i=0;i<root->children.size();i++){
		p->sum+=root->children[i]->data();
		
	}
	if(root->children.size()==0){
		return p;
	}
	for(int i=0;i<root->children.size();i++){
		pair *p1= treenode(root->children[i]);
		if (p1->sum>p->sum){
			p->data->p1->data;
			p->sum->p1->sum;
		}
	}
	return p;
}


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
		cout<<height<<endl;
		return root;
	
	
}


int main(){
	treenode<int> *node=takeinput();
	pair *t=maxsum(node);
	cout<<pair->data<<endl;
	
	return 0;
	
}
