# include <iostream>
# include <queue>
using namespace std;

void ksorted(int *a,int k,int n){
	priority_queue<int> q;
	for(int i=0;i<k;i++){
		q.push(a[i]);
	}
	int j=0;
	for(int i=k;i<n;i++){
		a[j]=q.top();
		q.pop();
		q.push(a[i]);
		j++;
	}
	while(!q.empty()){
		a[j]=q.top();
		q.pop();
		j++;
	}
	return;
	
}
int main(){
	int a[]={10,12,6,7,9};
	ksorted(a,3,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<endl;
	}
}
