#include <bits/stdc++.h>
using namespace std;
long long n;
vector<double> x, v;

bool f(double t){
    double xlower = -1e9, xupper = 1e9;
    for(int i=0; i<n; i++){
        double temp1 = x[i] - t*v[i], temp2 = x[i] + t*v[i];
        if(temp1 > xlower)
            xlower = temp1;
        if(temp2 < xupper)
            xupper = temp2;
    }
    if (xlower > xupper)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    x.resize(n);
    v.resize(n);
    for(long long i=0; i<n; i++){
        cin >> x[i] >> v[i];
    }
    double l = 0, r = 1e9, m;
    cout << setprecision(20);
    for(long long i=0; i<100; i++){
        m = (l+r)/2;
        if(f(m))
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
    return 0;
}
