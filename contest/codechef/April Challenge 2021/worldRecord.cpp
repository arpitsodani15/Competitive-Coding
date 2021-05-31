#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    float record = 9.58;
    cin >> T;
    for(int i=0; i<T; i++){
        float k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;
        float time = 100 / (k1*k2*k3*v);
        time = (int)(time * 100 + .5) / (float)100;
        if (time >= record)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    return 0;
}
