#include <bits/stdc++.h>
using namespace std;
 
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool isValid(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    bool vis[n][m];
    char cells[n][m];
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cells[i][j];
            if(cells[i][j] == '.'){
                cells[i][j] = 'X';
                count++;
                
            }
            vis[i][j] = false;
        }
    }
    int dots = count - k;
    bool done = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && cells[i][j] == 'X'){
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    cells[x][y] = '.';
                    dots--;
                    if(dots==0){
                        done = true;
                        break;
                    }
                    for(int t=0; t<4; t++){
                        int newX = x+dx[t], newY = y+dy[t];
                        if(isValid(newX, newY) && !vis[newX][newY] && cells[newX][newY] == 'X'){
                            vis[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                    if(done)    break;
                }
            }
            if(done)    break;
        }
        if(done)    break;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << cells[i][j];
        }
        cout << "\n";
    }
    return 0;
}