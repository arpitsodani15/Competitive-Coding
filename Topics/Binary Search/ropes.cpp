#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, k;

bool f(double x){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += floor(a[i]/x);
    }
    return sum >= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    double l=0, r=1e8;
    for(int i=0; i<100; i++) {
        double m = (l+r)/2;
        if(f(m))
            l=m;
        else
            r=m;
    }
    cout << setprecision(20) << l << "\n";
    return 0;
}
