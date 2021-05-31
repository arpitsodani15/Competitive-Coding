#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a=0, b=0, c=0;
    cin >> n;
    vector<int> arr;
    int temp, i=0;
    while (i<n) {
        cin >> temp;
        arr.push_back(temp);
        if (temp==1) 
            a++;
        else if (temp==2) 
            b++;
        else if (temp==3)
            c++;
        i++;
    }
    int min = a;
    if (b<min) 
        min=b;
    if (c<min) 
        min=c;
    cout << min << endl;
    for (int i=0; i<min; i++) {
        int c[3];
        for(int j=0; j<3; j++){
            // getting index and deleting value at it after getting the index once
            c[j] = find(arr.begin(), arr.end(), j+1) - arr.begin();
            arr[c[j]] = 0;
            cout << c[j]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
