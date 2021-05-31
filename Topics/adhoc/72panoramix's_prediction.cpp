#include <iostream>
using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<15; i++){
        if(n==primes[i] && m==primes[i+1]){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
