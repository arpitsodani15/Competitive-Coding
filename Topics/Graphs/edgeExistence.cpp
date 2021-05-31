#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector <bool>> a(n, vector<bool>(n, false));
    while(m--){
        int i, j;
        cin >> i >> j;
        a[i-1][j-1] = true;
    }
    int q;
    cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        if(a[i-1][j-1]) cout << "YES" << "\n";
        else    cout << "NO" << "\n";
    }
    return 0;
}
