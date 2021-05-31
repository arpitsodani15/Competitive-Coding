#include <bits/stdc++.h>
using namespace std;

long long n, m, d;
vector<long long> a, b, c;

bool f(long long s){
    
    return true;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> d;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=0; i<m; i++)  cin >> a[i] >> b[i] >> c[i];

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
