#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int win, lose, tie;
        if(n % 2 == 0){
            win = n/2 - 1;
            lose = win;
            tie = (n-1) - win - lose;
        }
        else{
            win = n/2;
            lose = n/2;
            tie = n-1 - win - lose;
        }
        vector<vector<int>> game(n+1, {win, tie, lose});
        
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(v==n)    break;
            for(int i=v+1; i<=n; i++){
                if(game[v][0]!=0){
                    game[v][0]--;
                    game[i][2]--;
                    cout << 1 << " ";
                }
                else if(game[v][1]!=0){
                    game[v][1]--;
                    game[i][1]--;
                    cout << 0 << " ";
                }
                else{
                    game[v][2]--;
                    game[i][0]--;
                    cout << -1 << " ";
                }
                q.push(i);
            }
        }
        cout << "\n";
    }
    return 0;
}