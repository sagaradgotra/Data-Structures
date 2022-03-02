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


class queueusingll{
	node *head;
	node *tail;
	int siz;
	
	public:
		queueusingll(){
			head=NULL;
			tail=NULL;
			siz=0;
		}
		
		bool isempty(){
			if (siz==0){
				return true;
			}
			else{
				return false;
			}
		}
		
		int size(){
			return siz;
		}
		
		void enqueue(int element){
			node *n=new node(element);
		
			if (siz==0){
				head=n;
				tail=n;
			}
			else{
				tail->next=n;
				tail=n;
			}
			siz++;
			 return;
		}
		
		int dequeue(){
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
		
		int front(){
			if (isempty()){
				cout<<"empty"<<endl;
				return 0;
			}
			else{
				return head->data;
			}
		}
};










