#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

bool f(long long x){
    return (x/w)*(x/h) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h >> n;
    long long l=0, r=2;
    while(!f(r))
        r *= 2;
    while(r>l+1){
        long long m = (l+r)/2;
        if(f(m))
            r=m;
        else
            l=m;
    }
    cout << r;
    return 0;
}
