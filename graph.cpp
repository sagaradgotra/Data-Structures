# include <bits/stdc++.h>

using namespace std;

void printDFS(int sv,int **out,int n,int *visited){
	cout<<sv<<endl;
	visited[sv]=1;
	for(int i=0;i<n;i++){
		if(visited[i]==1){
			continue;
		}
		if(sv==i){
			continue;
		}
		else{
			if(out[sv][i]==1){
				printDFS(i,out,n,visited);
			}
			
		}
	}
} 

vector<int> getpath(int sv,int end,int **out,int *visited,int n ,vector<int> &v){
	if(sv==end){
		v.push_back(end);
		visited[end]=1;
		return v;
	}
	for(int i=0;i<n;i++){
		if(out[sv][i]==1){
			if(visited[i]==1){
				continue;
			}
			else{
				visited[sv]=1;
				vector<int> m=getpath(i,end,out,visited,n,v);
				if(m.size()!=0){
					m.push_back(sv);
					return m;
				}
			}
		}
	}
	vector<int> b;
	return b;
	
}



void printBFS(int sv,int **out,int n,int *visited){
	queue<int> q;
	q.push(sv);
	visited[sv]=1;
	while(!q.empty()){
		int d=q.front();
		q.pop();
		cout<<d<<endl;
		//visited[d]=1;
		for(int i=0;i<n;i++){
			if(sv==i){
				continue;
			}
			if(out[sv][i]==1){
				if(visited[i]!=1){
					q.push(i);
					visited[i]=1;
				}
			}
		}
	}
}

void DFS(int n,int **out){
	int *visited=new int[n];
	for(int i=0;i<n;i++){
		if(visited[i]!=1){
			printDFS(i,out,n,visited);
			
		}
	}
}

void BFS(int n,int **out){
	int *visited=new int[n];
	for(int i=0;i<n;i++){
		if(visited[i]!=1){
			printBFS(i,out,n,visited);
		}
	}
}

void connected(int sv,int **out,int n,int *visited){
	//cout<<sv<<endl;
	//visited[sv]=1;
	for(int i=0;i<n;i++){
		if(visited[i]==1){
			continue;
		}
		if(sv==i){
			continue;
		}
		else{
			if(out[sv][i]==1){
				visited[sv]=1;
				connected(i,out,n,visited);
			}
			
		}
	}
	
} 


int main(){
	int a;
	int b;
	cin>>a>>b;
	int **out=new int*[a];
	for(int j=0;j<a;j++){
		out[j]=new int[a];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			out[i][j]=0;
		}
	}
	for(int i=0;i<b;i++){
		int e;
		int f;
		cin>>e>>f;
		out[e][f]=1;
		out[f][e]=1;
	}
	int *visited=new int[a];
	for(int i=0;i<a;i++){
		visited[i]=0;
	}
	//int p;
	//int t;
	//cin>>p>>t;
	//vector<int> v;
	//vector<int> c=getpath(p,q,out,visited,a,v);
	//for(int i=(c.size()-1);i>=0;i--){
	//	cout<<c[i]<<endl;
	//}
	
	connected(0,out,a,visited);
	int count=0;
	for(int i=0;i<a;i++){
		if(visited[i]==1){
			count++;
		}
	}
	if(count==a){
		cout<<"connected"<<endl;
	}
	else{
		cout<<"not connected"<<endl;
	}
	
	
	
	
	
	//BFS(a,out);
	return 0;
	
}
