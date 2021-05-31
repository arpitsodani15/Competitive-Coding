#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a, sum;

bool f(long long s){
    long long ss = 0, segment = 0;
    for(int i=0; i<n; i++){
        if(ss+a[i] <= s)
            ss += a[i];
        else if (ss!=0 && a[i] <= s){
            ss = a[i];
            segment++;
        }
        else if (a[i] > s) return false;
        if(i==n-1 && ss!=0) segment++;
    }
    if(segment > k)
        return false;
    return true;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++)  cin >> a[i];
    sum.resize(n);
    sum[0] = a[0];
    for(int i=1; i<n; i++)  sum[i] = sum[i-1] + a[i];
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
