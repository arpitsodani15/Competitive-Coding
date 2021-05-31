#include <bits/stdc++.h>
using namespace std;

int n, d, last, first;
vector<int> a;
vector<float>  sum, minSum;

bool f(float x){
    sum[0] = a[0]-x;
    minSum.resize(n);
    minSum[0] = sum[0];
    float minn = sum[0];
    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + a[i]-x;
        if(minn < sum[i])
            minn = sum[i];
        minSum[i] = minn;
    }
    for(int r=d; r<n; r++){
        if(minSum[r-d] <= sum[r-1]){
            last = r;
            first = r-d;
            return true;
        }
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    a.resize(n);
    sum.resize(n);
    for(int i=0; i<n; i++)  cin >> a[i];
    
    if(n==d){
        cout << 1 << " " << n;
        return 0;
    }
    float l=0, r=1000;
    
    for(int i=0; i<100; i++){
        float m = (l+r)/2;
        if(f(m))
            l=m;
        else
            r=m;
    }
    float av = 0;
    sum[0] = a[0];
    for(int i=1; i<n; i++){
        sum[i] = a[i-1]+a[i];
    }
    for(int i=0; i<last-d; i++){
        if (av > (sum[last] - sum[i])/(last-i)){
            av = (sum[last] - sum[i])/(last-i);
            first = i;
        }
    }
    cout << first << " " << last <<"\n";
    return 0;
}
