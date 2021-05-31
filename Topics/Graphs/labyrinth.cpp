#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
bool isValid(int x, int y){
    if(x>=n || x<0 || y>=m || y<0)
        return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    map<pair<int, int>, pair<int, int>> parent;
    pair<int, int> start, end;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<m; j++){
            if(a[i][j]=='A')
                start = make_pair(i, j);
            else if(a[i][j]=='B')
                end = make_pair(i,j);
        }
    }
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    parent[start] = make_pair(-1, -1);
    bool done = false;
    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x = v.first+dx[i], y = v.second+dy[i];
            pair<int, int> temp(x,y);
            if(isValid(x, y) && !vis[x][y] && (a[x][y] == '.' || a[x][y]=='B')){
                vis[x][y] = true;
                q.push(temp);
                parent[temp] = v;
                if(vis[end.first][end.second]){
                    done = true;
                    break;
                }
            }
        }
        if(done)
            break;
    }
    
    vector<pair<int, int>> ans;
    ans.push_back(end);
    if(done){
        cout << "YES\n";
        for(pair<int, int> u = parent[end]; u!=parent[start]; u=parent[u]){
            ans.push_back(u);
        }
        cout << ans.size()-1 << "\n";
        for(int i = ans.size()-1; i>0; i--){
            if(ans[i].first == ans[i-1].first){
                if(ans[i].second > ans[i-1].second)
                    cout << "L";
                else cout << "R";
            }
            else if(ans[i].second == ans[i-1].second){
                if(ans[i].first > ans[i-1].first)
                    cout << "U";
                else cout << "D";
            }
        }
    }
    else    cout << "NO";
 
 
    return 0;
}