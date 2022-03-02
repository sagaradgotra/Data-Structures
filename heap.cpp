# include<iostream>
using namespace std;
/*void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
	return;
}
*/

void heapsort(int* a){
	int i=1;
	int size=sizeof(a)/sizeof(a[0]);
	while(i<size){
		int child=i;
		while(child>0){
			int parent=(child-1)/2;
			if(a[parent]>a[child]){
				int temp=a[parent];
				a[parent]=a[child];
				a[child]=temp;
				child=parent;
			}
			else{
				break;
			}
		}
		i++;
		
	}
	
	i=1;
	int parent1=i;
	int left=2*i+1;
	int right=2*i+2;
	while(size>1){
		int temp1=a[i];
		a[i]=a[size-1];
		a[size-1]=temp1;
		size--;
		
	
	while(left<size or right<size){
				int b;
				if(left>size and right<size){
					b=min(a[parent1],a[right]);
		   		}
		   		else if(left<size and right>size){
		   			b=min(a[parent1],a[left]);
				}
				else{
				   b=min(a[parent1],min(a[left],a[right]));
				}
				if(b==a[parent1]){
					break;
				}
				int child1;
				if(left<size){
				
				if(a[left]==b){
					child1=left;
					a[child1]=a[parent1];
					a[parent1]=b;
					parent1=child1;
				    left=2*parent1+1;
			    	right=2*parent1+2;
				
				}
			}
				if(right<size){
				
				if(a[right]==b){
					child1=(2*parent1)+2;
					a[child1]=a[parent1];
					a[parent1]=b;
					parent1=child1;
					left=2*parent1+1;
					right=2*parent1+2;
				}
			}
	}
	
}
	
	return;		

	
}
int main(){
	int a[]={5,3,4,8,2};
	heapsort(a);
	int c=sizeof(a)/sizeof(a[0]);
	for(int g=0;g<c;g++){
		cout<<a[g]<<endl;
	}
	
	return 0;
}
