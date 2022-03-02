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
		if (lastindex==capacity){
			cout<<"full";
			return;
		}
		else{
			if (firstindex==-1){
				firstindex=0;
			}
			data[lastindex]=element;
			lastindex++;
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
			firstindex++;
			size--;
			return p; 
			
		}
	}
};
