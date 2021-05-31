#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    // taking size and getting array input
    int n, count=0, max=0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    // sorting
    sort(a, a+n);
    // counting the max occurance out of all the no.
    for (int i=0; i<n; i++){
        count = 0;
        for (int j=i; j<n; j++){
            if (a[i]==a[j])
                count++;
            else{
                i = j-1;
                break;
            }
        }
        if (count >= max)
            max = count;
    }
    // if max is more than ceil of (n/2) then NO
    if (max > ceil(n/2.0))
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
