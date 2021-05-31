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
    bool vis[n][m] = {false};
    char cells[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cells[i][j];
            vis[i][j] = false;
        }
    }
    queue<pair<int, int>> q;
    
    map<pair<int, int>, pair<int, int>> parent;
    int dist[n][m];
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]){
                char c = cells[i][j];
                q.push({i,j});
                vis[i][j] = true;
                parent[{i,j}] = {i, j};
                dist[i][j] = 0;
                while(!q.empty()){
                    pair<int, int> v = q.front();
                    q.pop();
                    for(int t=0; t<4; t++){
                        int x = v.first + dx[t], y = v.second + dy[t];
                        if(isValid(x, y) && cells[x][y]==c){
                            if(!vis[x][y]){
                                vis[x][y] = true;
                                q.push({x, y});
                                parent[{x, y}] = v;
                                dist[x][y] = dist[v.first][v.second] + 1;
                            }
                            else if(vis[x][y] && parent[v] != make_pair(x, y) 
                                    && (dist[x][y] + (dist[v.first][v.second] + 1)) >= 4){ //distance between start and end is atleast 4
                                cout << "Yes";
                            return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No";
    return 0;
}