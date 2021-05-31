#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n], check = 0;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        if(a[i]!=b[i]){
            check = 1;
        }
    }
    if (check==1){
        cout << "rated";
        return 0;
    }
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            check = 2;
            break;
        }
    }
    if(check==2)
        cout << "unrated";
    else
        cout << "maybe";
    return 0;
}
