#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }
    while(q--){
        int s;
        cin >> s;
        queue<pair<int, int>> q;
        vector<int> dist(n+1, 1e8+1);
        q.push({s, 0});
        dist[s] = 0;
        while(!q.empty()){
            pair<int, int> v = q.front();
            q.pop();
            for(pair<int, int> near : adj[v.first]){
                if(dist[near.first] > dist[v.first] + near.second){
                    dist[near.first] = dist[v.first] + near.second;
                    q.push(near);
                }
            }
        }
        int max = 0;
        for(int d : dist){
            if(d!=1e8+1 && max<d)
                max = d;
        }
        int count = 0;
        for(int d : dist){
            if(max==d)
                count++;
        }
        cout << max << " " << count << "\n";
        
    }


    

    return 0;
}
