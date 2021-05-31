#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector <int>> a(n);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    vector<int> dist(n);
    vector<bool> vis(n, false);
    dist[0] = 0;
    vis[0] = true;
    queue<int> q;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<a[v].size(); i++){
            if(dist[a[v][i]] > dist[v]+1){
                dist[a[v][i]] = dist[v]+1;
            }
            q.push(a[v][i]);
        }
    }

    pair<int, int> minn; // minn = (dist, id)
    int t;
    cin >> t;
    minn = make_pair(n-1, n);
    while(t--){
        int temp;
        cin >> temp;
        if(dist[temp] < minn.first){
            minn.first = dist[temp];
            minn.second = temp;
        }
        else if(dist[temp] == minn.first && temp < minn.second){
            minn.second = temp;
        }
    }
    cout << minn.second;

    return 0;
}
