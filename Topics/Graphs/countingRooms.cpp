#include <bits/stdc++.h>
using namespace std;

int n, m;

bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    char cells[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> cells[i][j];
    bool vis[n][m];
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    memset(vis, 0, sizeof(vis));
    int room = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && cells[i][j] == '.'){
                stack<pair<int, int>> s;
                s.push({i, j});
                vis[i][j] = true;
                while(!s.empty()){
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    for(int t=0; t<4; t++){
                        int newX = x+dx[t], newY = y+dy[t];
                        if(isValid(newX, newY) && !vis[newX][newY] && cells[newX][newY] == '.'){
                            vis[newX][newY] = true;
                            s.push({newX, newY});
                        }
                    }
                }
                room++;
            }
        }
    }
    
    cout << room;
    return 0;
}
