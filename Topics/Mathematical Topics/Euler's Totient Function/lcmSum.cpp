#include <bits/stdc++.h>
using namespace std;

vector<int> phi(1e6 + 1);

void phiCal(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    phiCal(1e6);
    
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> fac = factors(n);
        long long sum = 0;
        for(long long f : fac){
            sum += (f*phi[f]) + 1; 
        }
        sum = sum*n/2;
        cout << sum << "\n";
    }
    return 0;
}
