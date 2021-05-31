#include <iostream>
using namespace std;

int main() {
    long long n, m, count = 0;
    cin >> n >> m;
    count = n*(m/5);
    for (long long i=1; i<=n; i++){
        for (long long j=1; j<=m%5; j++){
            if ((i+j)%5==0)
                count++;
        }
    }
    cout << count;
    return 0;
}
