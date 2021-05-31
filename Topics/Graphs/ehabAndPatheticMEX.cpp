#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector <int>> a(n+1);
    pair<int, int> edges[n-1];
    int node = 0;
    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        edges[i-1] = {x, y};
        if(a[x].size()>=3)  node = x;
        else if(a[y].size()>=3) node = y;
    }
    int i=0;
    int nearNode = 0, min = 3;  // value 0, 1, 2 is given to edges on the node
    for(pair<int, int> e : edges){
        // cout << e.first << " " << e.second << ": ";
        if(node == 0){
            cout << i << "\n";
            i++;
        }
        else if(e.first == node || e.second == node){
            if(nearNode>2){             // if 0, 1, 2 all is given then minimum possible is given to next edge
                cout << min << "\n";
                min++;
            }
            else{
                cout << nearNode << "\n";
                nearNode++;
            }
        }
        else{
            cout << min << "\n";
            min++;
        }
    }
    return 0;
}
