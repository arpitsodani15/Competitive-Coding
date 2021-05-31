#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;

void factors(u64 n) {
    vector<u64> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<u64, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    u64 i = 0;
    for (u64 d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    set<u64> s(factorization.begin(), factorization.end());
    for(u64 factor : s){
        cout << factor << "^" << count(factorization.begin(), factorization.end(), factor) << " ";
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        u64 temp;
        cin >> temp;
        if(temp == 0)   break;
        factors(temp);
        cout << "\n";
    }
    return 0;
}
