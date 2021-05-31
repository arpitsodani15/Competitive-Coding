#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int j=0;
    for (int i=0; i<n; i++){
        if (j==k)
            j -= k;
        char c = 'a' + j;
        cout << c;
        j++;
    }
    return 0;
}
