#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    if(A==B || A==C || B==C)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
