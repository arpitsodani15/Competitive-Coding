#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp==1)
                a[i].push_back(j);
        }
    }
    for(int i=0; i<n; i++){
        vector<int> dist(n, 5000);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        int check = 1;
        for(int j=0; j<a[i].size(); j++){
            if(a[i][j]==i){
                cout << 1 << "\n";
                check = 0;
            }
        }
        if(check = 0)
            continue;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int j=0; j<a[v].size(); j++){
                if(dist[a[v][j]]>dist[v]+1 && v!=a[v][j]){
                    dist[a[v][j]] = dist[v]+1;
                    q.push(a[v][j]);
                }
            }
        }
        cout << dist[i] << "\n";
    }

    return 0;
}
