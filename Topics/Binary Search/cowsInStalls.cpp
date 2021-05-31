#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a, ans;

long long closestToRight(long long x){
    long long l = -1, r = n, m;
    while(r>l+1){
        m = (l+r)/2;
        if(a[m] < x)
            l=m;
        else
            r=m;
    }
    return r;
}
bool f(long long s){
    long long curr = a[0], index=0;
    for(long long i=1; i<k; i++){
        index = closestToRight(curr+s);
        if(index == n)  return false;
        curr = a[index];
        ans[i] = curr;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    ans.resize(k);
    for(long long i=0; i<n; i++)  cin >> a[i];
    long long l=0, r=2;
    while(f(r))
        r *= 2;
    while(r>l+1){
        long long m = (l+r)/2;
        if(f(m))
            l=m;
        else
            r=m;
    }
    cout << l;
    
    return 0;
}
