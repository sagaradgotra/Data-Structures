# include <iostream>
# include <vector>
# include <queue>
using namespace std;

vector<int> ksmallest(int* a,int k,int n){
	priority_queue<int> q;
	for (int i=0;i<k;i++){
		q.push(a[i]);
	}
	for (int i=k;i<n;i++){
		if(q.top()>a[i]){
			q.pop();
			q.push(a[i]);
		}
	}
	vector<int> v;
	while(!q.empty()){
		v.push_back(q.top());
		q.pop();
	}
	return v;
}
int main(){
	int a[]={2,5,7,4,9,10,3,24,32,12};
	vector<int> c=ksmallest(a,4,10);
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<endl;
		
	}
	
	return 0;
	
}
