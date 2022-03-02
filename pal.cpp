# include <iostream>
# include "node.h"
using namespace std;
int size(node *h){
	if(h==NULL){
		return 0;
		
	}
	h=h->next;
	return size(h)+1;
	
}

node* mid(node *h){
	int p=size(h);
	int i=0;
	node *temp=h;
	if(p%2==0){
		
	while (i<(p/2)-1){
		temp=temp->next;
		i++;
		
	}
}
else{
	int k=p/2;
	while(i<k){
		temp=temp->next;
		i++;
	}
}
return temp;
}

node* reverse(node *h){
	if(h->next==NULL){
		return h;
	}
	
	
	node *j= reverse(h->next);
	
	j->next=h;
	h->next=NULL;
	return j;
	
	
	
}
node* takeinput(){
	int s;
	cin>>s;
	int l;
	l=0;
	node *head=NULL;
	node *tail=NULL;
	while(s!=-1){
	
	node *n=new node(s);
	if(head==NULL){
		head=n;
		tail=n;
		l++;
	}
	else{
		tail->next=n;
		tail=n;
		l++;
		
		
	}
	cin>>s;
}
	//cout<<l<<endl;
    return head;
	
	
}


int main(){
	node* h=takeinput();
	
	node *s=mid(h);
	
	node *k=reverse(s);
	s->next=NULL;
	while (h->data==k->data and h!=NULL and k!=NULL){
		h=h->next;
		k=k->next;
		
	}
	if (h==NULL and k==NULL){
		cout<<"true"<<endl;
	}
	else if(k==NULL){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	
	
}
