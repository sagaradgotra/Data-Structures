#include <bits/stdc++.h>
using namespace std;

class edge{
	public:
		int v1;
		int v2;
		int weight;
	
};

bool comp(edge a,edge f){
	if(a.weight<f.weight){
		return true;
	}
	return false;
}

int parent(int a,int *arr){
	int p=a;
	while(arr[p]!=p){
		p=arr[p];
	}
	return p;
}

int main(){
	int e;
	int v;
	cout<<"Enter no of edges:"<<endl;
	cin>>e;
	cout<<"Enter no of vertices:"<<endl;
	cin>>v;
	edge* arr=new edge[e];
	edge* out=new edge[v-1];
	int *a=new int[v];
	for(int i=0;i<v;i++){
		a[i]=i;
	}
	for(int i=0;i<e;i++){
		int v1;
		int v2;
		int we;
		cout<<"vertex1:"<<endl;
		cin>>v1;
		cout<<"vertex2:"<<endl;
		cin>>v2;
		cout<<"weight:"<<endl;
		cin>>we;
		arr[i].v1=v1;
		arr[i].v2=v2;
		arr[i].weight=we;
		
	}
	sort(arr,arr+e,comp);
	int y=0;
	int i=0;
	while(y!=v-1){
		edge w=arr[i];
		int sp=parent(w.v1,a);
		int dp=parent(w.v2,a);
		if(sp!=dp){
			out[y]=w;
			y++;
			a[sp]=dp;
		}
		i++;
		
	}
	
	for(int i=0;i<v-1;i++){
		cout<<out[i].v1<<" "<<out[i].v2<<" "<<out[i].weight<<endl;
	}
	
	return 0;
	
}
