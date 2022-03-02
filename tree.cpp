# include <iostream>
# include <queue>
using namespace std;
template <typename T>
class binarytreenode{
	public:
	T data;
	binarytreenode<T> *left;
	binarytreenode<T> *right;
	
	binarytreenode(T element){
		this->data=element;
		left=NULL;
		right=NULL;
		
	} 
};



void inorder(binarytreenode<int> *root){
	if (root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
	
}

void preorder(binarytreenode<int> *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}

void postorder(binarytreenode<int> *root){
	if (root==NULL){
		return;
	}
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<endl;
}

void bfs_traversal(binarytreenode<int> *root){
	queue<binarytreenode<int>* > q;
	q.push(root);
	while(!q.empty()){
		binarytreenode<int> *temp=q.front();
		q.pop();
		cout<<temp->data<<"->";
		if(temp->left){
			q.push(temp->left);
			
		}
		if(temp->right){
			q.push(temp->right);
			
		}
		
		
	}
	cout<<""<<endl;
	return;
	
	
}
int main(){
	
	binarytreenode<int> *root1=new binarytreenode<int>(1);
	binarytreenode<int> *root2=new binarytreenode<int>(2);
	binarytreenode<int> *root3=new binarytreenode<int>(3);
	binarytreenode<int> *root4=new binarytreenode<int>(4);
	binarytreenode<int> *root5=new binarytreenode<int>(5);
	root1->left=root2;
	root1->right=root3;
	root2->left=root4;
	root2->right=root5;
	
	cout<<"BFS traversal:"<<endl;
	bfs_traversal(root1);
	cout<<"Inorder traversal:"<<endl;
	inorder(root1);
	cout<<"Preorder traversal:"<<endl;
	preorder(root1);
	cout<<"Postorder traversal:"<<endl;
	postorder(root1);
	
}

