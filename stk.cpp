# include <iostream>
using namespace std;
class stack{
	int *data;
	int nextindex;
	int capacity;
	
	
	public:
		 stack(){
		 	data=new int[4];
		 	nextindex=0;
		 	capacity=4;
			
		}
		void push(int element){
			if(nextindex==capacity){
				int *data1=new int[2*capacity];
				for(int i=0;i<capacity;i++){
					data1[i]=data[i];
				}
				data1[nextindex]=element;
				capacity=2*capacity;
				nextindex++;
				
				delete [] data;
				data=data1;
				return;
			}
			else{
				data[nextindex]=element;
				nextindex++;
				return;
			}
			
			
			
		}
		
		int pop(){
			if (nextindex==0){
				
				return 0;
			}
			else{
				int p=data[nextindex-1];
				nextindex--;
				return p;
				
			}
		}
		int top(){
			if (nextindex==0){
				return 0;
				
			}
			else{
				return data[nextindex-1];
			}
		}
		
		
		int size(){
			return nextindex;
		}
		
		bool empty(){
			if (nextindex==0){
				return true;
			}
			else{
				return false;
			}
		}
};
int main(){
	stack st;
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	cout<<st.size()<<endl;
	int d=st.top();
	cout<<"Element at top:"<<d<<endl;
	int c=st.pop();
	cout<<"Element removed:"<<c<<endl;
	cout<<"Number of elements in stack:"<<st.size()<<endl;
	cout<<"Is the stack empty:"<<st.empty()<<endl;
	
	
	return 0;
	
}
