#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string ssss = to_string(N);
    for(int ii=0; ii<ssss.length(); ii++){
        int tempp = ssss[ii]-'0';
        cout << 9-tempp;
    }
    return 0;
}
