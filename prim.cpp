#include <bits/stdc++.h>
#define li long long int
using namespace std;

li findMinVertex(li* weights, bool* visited, li n);

void prims(li** edges, li n);

signed main() {
	li n;
	li e;
	cin >> n >> e;
	li** edges = new li*[n];
	for (li i = 0; i < n; i++) {
		edges[i] = new li[n];
		for (li j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (li i = 0; i < e; i++) {
		li f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	
	cout << "OUTPUT:" << endl;
	prims(edges, n);

	for (li i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

li findMinVertex(li* weights, bool* visited, li n){

	li minVertex = -1;
	for(li i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}
void prims(li** edges, li n){

	li* parent = new li[n];
	li* weights = new li[n];
	bool* visited = new bool[n];

	for(li i = 0; i < n; i++){
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	parent[0] = -1;
	weights[0] = 0;

	for(li i = 0; i < n - 1; i++){
		li minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;
		for(li j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(li i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << " "  << i << " " << weights[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
}
