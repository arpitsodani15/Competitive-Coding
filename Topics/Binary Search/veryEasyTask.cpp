#include <bits/stdc++.h>
using namespace std;

long long n, x, y;

bool f(long long t){
    long long slow = max(x,y), fast = min(x,y);
    return ((t/fast)+((t-fast)/slow)) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
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
    cout << r << "\n";
    return 0;
}
