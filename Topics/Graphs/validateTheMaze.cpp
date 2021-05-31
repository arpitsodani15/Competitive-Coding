#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> m >> n;
        
        vector<string> a(m);
        map<pair<int, int>, bool> vis;
        for(int i=0; i<m; i++){
            cin >> a[i];
            for(int j=0; j<n; j++){
                vis.insert(pair<pair<int, int>, bool>(make_pair(i, j), false));
            }
        }
        if(n==m && m==1){
            cout << "invalid\n";
            continue;
        }
        vector<pair<int, int>> opening;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && a[i][j]=='.')
                    opening.push_back(make_pair(i, j));
            }
        }
        
        if(opening.size()!=2){
            cout << "invalid\n";
            continue;
        }
        
        pair<int, int> start = opening[0], end = opening[1];
        if((abs(start.first-end.first)==1 && start.second==end.second)
        || (start.first==end.first && abs(start.second-end.second)==1)){
            cout << "valid\n";
            continue;
        }
        queue<pair<int, int>> q;
        q.push(start);
        vis[start] = true;
        while(!q.empty()){
            pair<int, int> v = q.front();
            q.pop();
            vector<pair<int, int>> close{make_pair(v.first, v.second)};
            if(v.first-1>=0) close.push_back(make_pair(v.first-1, v.second));
            if(v.first+1<m) close.push_back(make_pair(v.first+1, v.second));
            if(v.second-1>=0) close.push_back(make_pair(v.first, v.second-1));
            if(v.second+1<n) close.push_back(make_pair(v.first, v.second+1));

            for(pair<int, int> i: close){
                if(!vis[i] && a[i.first][i.second]=='.'){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        if(vis[end])
            cout << "valid\n";
        else
            cout << "invalid\n";
    }
    return 0;
}
