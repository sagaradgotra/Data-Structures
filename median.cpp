# include <iostream>
# include <queue>
using namespace std;
int main(){
	priority_queue<int> max;
	priority_queue<int,vector<int>,greater<int> > min;
	int n;
	cin>>n;
	int a;
	cin>>a;
	max.push(a);
	cout<<max.top()<<endl;
	for(int i=1;i<n;i++){
		int h;
		cin>>h;
		
		if(h>max.top()){
			min.push(h);
			if(min.size()-max.size()>1){
				int c=min.top();
				min.pop();
				max.push(c);
				int d=(min.top()+max.top())/2;
				cout<<d<<endl;
			}
			else if (min.size()==max.size()){
				int e=(min.top()+max.top())/2;
				cout<<e<<endl;
			}
			else{
				cout<<min.top()<<endl;
			}
		}
		else{
			max.push(h);
			if(max.size()-min.size()>1){
				int g=max.top();
				max.pop();
				min.push(g);
				int t=(min.top()+max.top())/2;
				cout<<t<<endl;
			}
			else if (max.size()==min.size()){
				int u=(max.top()+min.top())/2;
				cout<<u<<endl;
			}
			else{
				cout<<max.top()<<endl;
			}
			
		}
	}
	return 0;
}
