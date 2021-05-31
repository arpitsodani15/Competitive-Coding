#include <bits/stdc++.h>
using namespace std;

double c;

double f(double x){
    return (x*x) + sqrt(x) - c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c;
    double l=0, r=1e6, m;
    cout << setprecision(20);
    for(int i=0; i<100; i++) {
        m = (l+r)/2;
        if(f(m) > 0)
            r = m;
        else
            l = m;
    }
    cout << m;
    return 0;
}
