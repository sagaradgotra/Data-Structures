# include <iostream>
# include "node.h"
using namespace std;

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

int mid(node *h){
	node *slow=h;
	node *fast=h->next;
	while (fast!=NULL){
		if (fast->next==NULL){
			return slow->data;
		}
		else{
			slow=slow->next;
			fast=fast->next->next;
		}
		
	}
	return slow->data;
}

void reverse(node *h){
	if(h==NULL){
		return;
	}
	
	
	reverse(h->next);
	cout<<h->data<<endl;
	
	
	
}

int index(node *head,int n){
	node *temp=head;
	int i=0;
	while (temp!=NULL){
		if (temp->data==n){
			return i;
		}
		else{
			temp=temp->next;
			i++;
		}
		
	}
	return -1;
}


node* duplicate(node *h){
	node *temp=h;
	
	while(temp!=NULL){
	
	int p=temp->data;
	node *a=temp->next;
	if (p==a->data){
		
		
		node *temp1=temp;
	
	while(p==temp->data){
		
		temp=temp->next;
	}
	
	
	temp1->next=temp;
}

	else{
		temp=temp->next;
	}
}
return h;
	
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

int size(node *h){
	if(h==NULL){
		return 0;
		
	}
	h=h->next;
	return size(h)+1;
	
}

node *merge(node *h1,node *h2){
	node *d1=h1;
	node *d2=h2;
	int j=0;
	
	if(d1->data>=d2->data){
		int j=1;
	}

	int g=2;
	node *d5=d2;
	node *d4=d1;
	while(d1!=NULL and d2!=NULL){
			
		if (d1->data<=d2->data){
			if (g==1){
				node *d4=d1;
				d5->next=d4;
				d1=d1->next;
				int g=0;
			}
			else{
				d1=d1->next;
				int g=0;
			}
			
			
			
		}
		else{
			if (g==0){
				d4->next=d2;
				node *d5=d2;
			
				d2=d2->next;
				int g=1;
			}
			else{
				d2=d2->next;
				int g=1;
			}
			
		
			
			d2=d2->next;
		}
	}
	if (d1==NULL){
		d4->next =d2;
	}
	else if(d2==NULL){
		d5->next=d1;
	}
	if (j==1){
		return h2;
	}
	else{
		return h1;
		
	}
	
}



int mid1(node *h){
	
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
return temp->data;
}




/*
node* insertrec(node *h,int i,int data){
	if (h==NULL and i==0){
		node *n=new node(data);
		n->next=h;
		h=n;
		return h;
		
	}
	else{
		h->next=insertrec(h->next,i-1,data);
	}
	
}
*/









int main(){
	node *h1=takeinput();
	node *h2=takeinput();
	node *p=merge(h1,h2);
	print(p);
	
	
	
	
	
	return 0;
}
