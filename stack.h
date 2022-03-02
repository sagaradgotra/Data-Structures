template <typename T>
class stack{
	T *data;
	int nextindex;
	int capacity;
	
	
	public:
		 stack(){
		 	data=new T[4];
		 	nextindex=0;
		 	capacity=4;
			
		}
		void push(T element){
			if(nextindex==capacity){
				T *data1=new T[2*capacity];
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
				T p=data[nextindex-1];
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
