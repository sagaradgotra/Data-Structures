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


class stackusingll{
	node *head;
	int siz;
	
	public:
		stackusingll(){
			
			head=NULL;
			siz=0;
			
			
			
		}
		bool isempty(){
			if(head==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		int size(){
			return siz;
			
		}
		
		int pop(){
			if(isempty()){
				cout<<"empty"<<endl;
				return 0;
			}
			else{
			
			int p;
			p=head->data;
			node *temp=head; 
			head=head->next;
			delete temp;
			siz--;
			return p;
			
		}
			
		}
		
		void push(int element){
			
			
			node *n=new node(element);
			n->next=head;
			head=n;
			siz++;
			return ;
			
			
		}
		
		int top(){
			if(isempty()){
				return 0;
			}
			else{
			
			return head->data;
			
		}
		} 
};
