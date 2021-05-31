#include <iostream>
using namespace std;
#define infi 10000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    string line;
    cin >> line;
    long long posi[n];
    long long min_diff = infi, diff, i1, i2;
    for (long long i=0; i<n; i++){
        cin >> posi[i];
        if (i!=0)
            diff = posi[i]-posi[i-1];
        if (i!=0 && diff < min_diff && line[i]=='L' && line[i-1]=='R'){
            min_diff = diff;
            i1 = i-1;
            i2 = i;
        }
    }
    if (min_diff==infi){
        cout << -1;
        return 0;
    }
    cout << min_diff/2;
    return 0;
}
