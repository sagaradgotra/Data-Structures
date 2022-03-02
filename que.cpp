# include<iostream>
using namespace std;
class queue{
	int *data;
	int firstindex;
	int lastindex;
	int size;
	int capacity;
	
	public:
	
	queue(int s){
		data=new int[s];
		capacity=s;
		size=0;
		firstindex=-1;
		lastindex;
		
	}
	
	int siz(){
		return size;
	}
	bool isempty(){
		return size==0;
	}
	int front(){
		int g;
		g=data[firstindex];
		
	}
	void enqueue(int element){
		if (size==capacity){
			cout<<"full";
			return;
		}
		else{
			if (firstindex==-1){
				firstindex=0;
			}
			data[lastindex]=element;
			lastindex=(lastindex+1)%capacity;
			size++;
			return;
			
		}
		
	}
	
	int dequeue(){
		if (size==0){
			cout<<"Empty"<<endl;
			return 0;
		}
		else{
			int p;
			p=data[firstindex];
			firstindex=(firstindex+1)%capacity;
			size--;
			return p; 
			
		}
	}
};
int main(){
	queue q(5);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(50);
	q.enqueue(60);
	cout<<"Size of queue:"<<q.siz()<<endl;
	int g=q.dequeue();
	cout<<"Element removed:"<<g<<endl;
	cout<<"Size of queue:"<<q.siz()<<endl;
	cout<<"Front element:"<<q.front()<<endl;
	
	
	return 0;
	}

