#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();
    vector <int> arr;
    for (int i=0; i<l;){
        int temp = s[i]-48;
        arr.push_back(temp);
        i += 2;
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<arr.size(); i++) {
        if (i==0)
            cout << arr[i];
        else
            cout << "+" << arr[i];
    }
    return 0;
}
