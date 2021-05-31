#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector <int>> a(n+1);
    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bool vis[n+1] = {false};
    int s = 1;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    double expect=0;
    float prob[n+1];
    int dist[n+1];
    prob[s] = 1;
    dist[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : a[v]){
            if(!vis[i]){
                q.push(i);
                dist[i] = dist[v]+1;
                vis[i]=true;
                if(v==1)
                    prob[i] = prob[v]/a[v].size();
                else
                    prob[i] = prob[v]/(a[v].size()-1);
                if(a[i].size()==1)
                    expect += prob[i]*dist[i];
            }
        }
    }
    
    cout << setprecision(10) << expect;
    return 0;
}
