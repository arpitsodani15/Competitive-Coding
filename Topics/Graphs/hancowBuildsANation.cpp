#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> nodes;
vector<int> govern;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    govern.resize(k);
    for(int i=0; i<k; i++)
        cin >> govern[i];

    nodes.resize(n+1);
    vis.resize(n+1);
    
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++)
        vis[i] = false;
    
    vector<int> cntNodes(k+1);
    for(int i : govern){
        queue<int> q;
        int count = 1;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int t : nodes[v]){
                if(!vis[t]){
                    vis[t] = true;
                    q.push(t);
                    count++;
                }
            }
        }
        cntNodes.push_back(count);
    }

    int count = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i])
            count++;
    }

    sort(cntNodes.begin(), cntNodes.end(), greater<int>());
    int total=0;
    for(int i=0; i<cntNodes.size(); i++){
        if(i==0)
            total += ((cntNodes[0] + count)*(cntNodes[0] + count - 1))/2;
        else
            total += (cntNodes[i]*(cntNodes[i] - 1))/2;
    }

    cout << total - m;
    return 0;
}
