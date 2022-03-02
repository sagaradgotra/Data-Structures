# include <iostream>
# include <math.h>
# include <vector>
using namespace std;
class priorityqueue{
	vector<int> v;
	
	public:
		
		bool isempty(){
			return v.size()==0;
		}
		int getmin(){
			if(isempty()){
				return 0;
			}
			return v[0];
		}
		int size(){
			return v.size();
		}
		void insert(int element){
			v.push_back(element);
			int childidx=v.size()-1;
			while(childidx>0){
			int parent=(childidx-1)/2;
			if(v[childidx]<v[parent]){
				int temp=v[childidx];
				v[childidx]=v[parent];
				v[parent]=temp;
				
			}
			else{
				break;
			}
			childidx=parent;
		}
			
			
			
		}
		
		int remove(){
			int child=v.size()-1;
			int ans=v[0];
			v[0]=v[child];
			int parent=0;
			vector<int> :: iterator it=v.begin()+child;
			v.erase(it);
			int left=2*parent+1;
			int right=2*parent+2;
			while(left<v.size() or right<v.size()){
				int b;
				if(left>v.size() and right<v.size()){
					b=min(v[parent],v[right]);
		   		}
		   		else if(left<v.size() and right>v.size()){
		   			b=min(v[parent],v[left]);
				}
				else{
				   b=min(v[parent],min(v[left],v[right]));
				}
				if(b==v[parent]){
					break;
				}
				int child1;
				if(left<v.size()){
				
				if(v[left]==b){
					child1=left;
					v[child1]=v[parent];
					v[parent]=b;
					parent=child1;
				    left=2*parent+1;
			    	right=2*parent+2;
				
				}
			}
				if(right<v.size()){
				
				if(v[right]==b){
					child1=(2*parent)+2;
					v[child1]=v[parent];
					v[parent]=b;
					parent=child1;
					left=2*parent+1;
					right=2*parent+2;
				}
			}
			}
			
			
		return ans;	
		}
	};

		
		
		
		
		
		
		
		
		
		
		
		
		

