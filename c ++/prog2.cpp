#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
    int src,dest,weight;
};

bool compareEdges(const  Edge &a ,const Edge &b) {
    return a.weight<b.weight;
}

class Disjointset {
        vector<int> parent,rank;
public:
    Disjointset(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }

    int find(int node) {
        if(parent[node] !=node)
         parent[node]=find(parent[node]);
         return parent[node];
    }


    void unionSets(int u,int v) {
        int rootU=find(u);
        int rootV=find(v);

        if(rootU != rootV) {
            if(rank[rootU] > rank[rootV]) {
                parent[rootV]=rootU;
            } else if (rank[rootU] < rank[rootV])
            {
                parent[rootU]=rootV;
            } else {
                parent[rootV]=rootU;
                rank[rootU]++;
            }       
        }
    }

};


void krushkalMST (int n , vector<Edge> &edges){
    sort(edges.begin(),edges.end(),compareEdges);
    Disjointset ds(n);

    vector<Edge> mst;
    int minCost=0;

    for (const Edge &edge:edges)
    {
        if(ds.find(edge.src) != ds.find(edge.dest)) {
            mst.push_back(edge);
            minCost=edge.weight;
            ds.unionSets(edge.src,edge.dest);
        }
        if(mst.size()==n-1)break;

    }

    cout << "\n Minimum cost spanning tree : \n";
    for(size_t i=0; i<mst.size();++i){
        cout << mst[i].src << "--" << mst[i].dest <<"--" <<mst[i].weight<< "\n";
    }
     cout << "Total Minimum cost:" << minCost <<endl;


}

int main() {
    int n,e;
    cout << "\n Enter the number of nodes and edges: \n";
    cin >> n>> e;

    vector<Edge> edges(e);

    cout<< "\n Enter edges(source,destination,weight):\n";
    for (int i=0;i<e;i++) {
        cin>> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    krushkalMST(n,edges);

    return 0;
}






