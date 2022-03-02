# include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(int element){
		this->data=element;
		next=NULL;
	}
	
	
};

node* takeinput(){
	int s;
	cin>>s;
	node *head=NULL;
	node *tail=NULL;
	while(s!=-1){
	
	node *n=new node(s);
	if(head==NULL){
		head=n;
		tail=n;
		
	}
	else{
		tail->next=n;
		tail=n;
		
		
		
	}
	cin>>s;
}
	return head;
}


void print(node *head){
	node *temp=head;
	while(temp!=NULL){
	
	int p;
	p=temp->data;
	cout<<p<<endl;
	temp=temp->next;
}
	
}


int count(node *h){
	if(h==NULL){
		return 0;
		
	}
	h=h->next;
	return count(h)+1;
	
}

node* insert(node* head,int pos,int element){
	if(pos==0){
		node* newnode=new node(element);
		newnode->next=head;
		return newnode;
	}
	if(pos>count(head)-1){
		return head;
	}
	int i=0;
	node* temp=head;
	while(i<pos){
		temp=temp->next;
		i++;	
	}
	node* newnode=new node(element);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}

node* deletenode(node* head,int pos){
	if(pos==0){
		node *newnode=head->next;
		delete(head);
		return newnode;
	}
	if(pos>count(head)-1){
		return head;
	}
	int i=0;
	node *temp=head;
	while(i<pos){
		temp=temp->next;
		i++;
	}
	node *temp1=temp->next->next;
	delete(temp->next);
	temp->next=temp1;
	return head;
}

int main(){
	node* n1=new node(10);
	node* n2=new node(20);
	node* n3=new node(30);
	node* n4=new node(40);
	node* n5=new node(50);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	
	print(n1);
	cout<<"Enter the elements of linked list:"<<endl;
	node *head=takeinput();  //let input given is 1,2,3,4,5,6 and -1 to stop input
	print(head);
	cout<<"Length of linked list:"<<count(head)<<endl;
	insert(head,3,10);
	cout<<"Linked list after insertion:"<<endl;
	print(head);
	cout<<"New length of linked list:"<<count(head)<<endl;
	deletenode(head,4);
	cout<<"Linked list after deletion:"<<endl;
	print(head);
	return 0;
}
