#include <iostream>
using namespace std;

int main() {
    long long n, temp=0;
    cin >> n;
    if (n%2!=0)
        cout << (-n-1)/2;
    else
        cout << n/2;
    return 0;
}
