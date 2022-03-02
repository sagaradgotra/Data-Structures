#include <bits/stdc++.h>
#define li long long int
using namespace std;

class Edge{
    public:
    li start;
    li destination;
    li weight;
};

bool cmp(const Edge e1,  const Edge e2);
li getparent(li* parent, li index);

void kruskalAlgorithm(Edge* edges,li v,li e){
    sort(edges,edges+e,cmp);
    Edge* mst = new Edge[v-1];
    li* parent = new li[v];
    for(li i = 0;i < v;i++){
        parent[i] = i;
    }
    li count = 0;
    li i = 0;
    while(count < v-1){
        li p1 = getparent(parent,edges[i].start);
        li p2 = getparent(parent,edges[i].destination);
        if(p1 != p2){
            mst[count] = edges[i];
            count++;
            parent[p1] = p2;
        }
        i++;
    }
    for(li i = 0;i < v-1;i++){
        Edge edge = mst[i];
        if(edge.start > edge.destination){
            cout << edge.destination << " " << edge.start << " " << edge.weight << endl; 
        }else{
            cout << edge.start << " " << edge.destination << " " << edge.weight << endl;
        }
    }
}

signed main() {
    li v,e;
    cin >> v >> e;
    Edge* edges = new Edge[e];
    for(li i = 0;i < e;i++){
        li start,weight,destination;
        cin >> start >> destination >> weight;
        edges[i].start = start;
        edges[i].destination = destination;
        edges[i].weight = weight;
    }
    cout << "----------------------------" << endl;
    cout << "OUTPUT:" << endl;
     kruskalAlgorithm(edges,v,e);
}

bool cmp(const Edge e1,  const Edge e2){ 
    return e1.weight < e2.weight;
}
li getparent(li* parent, li index){
    while(parent[index] != index){
        index = parent[index];
    }
    return index;
}