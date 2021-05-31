#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int d[8] = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
    while(t--){
        int x;
        cin >> x;
        int i;
        for(i=0; i<8; i++){
            if(x%d[i]==0){
                cout <<"Yes";
                break;
            }
        }
        if(x%d[i]==0)   continue;
        if(x<d[1]){
            cout << "NO\n";
            continue;
        }
        

    }
    return 0;
}
