#include <iostream>
using namespace std;

int main() {
    long long n, left=0;
    long long x, d;
    char c;
    cin >> n >> x;
    for (long long i=0; i<n; i++){
        cin >> c >> d;
        if (c == '+')
            x += d;
        if (c == '-')
            if(x < d){
                left++;
                continue;
            }
            else
                x -= d;
    }
    cout << x << " " << left;
    return 0;
}
