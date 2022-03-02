# include <iostream>
# include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	queue<int> q;
	for(int i=0;i<n;i++){
		q.push(i);
		
	}
	priority_queue<int> p;
	for(int i=0;i<n;i++){
		p.push(a[i]);
	}
	int count=0;
	while(q.front()!=k or p.top()!=a[k]){
		if (a[q.front()]==p.top()){
			p.pop();
			q.pop();
			count++;
			
		}
		else{
			int b=q.front();
			q.pop();
			q.push(b);
		}
	}
	int c=count+1;
	cout<<c<<endl;
	
	
}
