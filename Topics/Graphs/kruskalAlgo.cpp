#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0; i<m; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[i].src = s-1, edges[i].dest = d-1, edges[i].weight = w;
    }
    vector<int> parent(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    vector<Edge> result;
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(Edge e: edges){
        
        if(parent[e.src] != parent[e.dest]){
            cost += e.weight;
            result.push_back(e);

            int oldParent = parent[e.src], newParent = parent[e.dest];
            for(int i=0; i<n; i++){
                if(parent[i] == oldParent){
                    parent[i] = newParent;
                }
            }
        }
    }
    cout << "\n" << cost << "\n";
    for(Edge e: result){
        if(e.src < e.dest)
            cout << e.src+1 << " " << e.dest+1 << " " << e.weight << "\n";
        else
            cout << e.dest+1 << " " << e.src+1 << " " << e.weight << "\n";
    }

    return 0;
}
