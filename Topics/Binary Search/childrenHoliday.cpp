#include <bits/stdc++.h>
using namespace std;

long long m, n;
vector<long long> t, y, z, ans;

bool f(long long time){
    long long sum=0;
    for(long long i=0; i<n; i++){
        long long x = (z[i]/((t[i]*z[i]) + y[i])) * time;
        long long w = time - (x*t[i]) + (x*y[i]/z[i]);
        if(w/t[i] >= z[i])  x += z[i];
        else    x += w/t[i];
        sum += x;
        ans[i] = x;
        if(sum >= m)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    ans.resize(n);
    for (long long i=0; i<n; i++){
        cin >> t[i] >> z[i] >> y[i];
    }
    if(m==0){
        cout << 0 << "\n";
        for(long long i=0; i<n; i++)
            cout << 0 << " ";
        return 0;
    }
    long long l=0, r=1e9;
    while(r>l+1){
        long long m = (l+r)/2;
        if(f(m))
            r=m;
        else
            l=m;
    }
    cout << r << "\n";
    for(long long i=0; i<n; i++)
        cout << ans[i] << " ";
    return 0;
}
