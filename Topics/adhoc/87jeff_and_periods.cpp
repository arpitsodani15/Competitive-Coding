#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int lastPosi[100001], diff[100001];
    fill_n(lastPosi, 100001, -1);
    fill_n(diff, 100001, -1);
    int temp ;
    for(int i=0; i<n; i++){
        cin >> temp;
        if (lastPosi[temp]==-1){
            lastPosi[temp] = i;
            diff[temp] = 0;
        }
        else {
            int d = i-lastPosi[temp];
            if (d != diff[temp] && diff[temp]){
                lastPosi[temp] = i;
                diff[temp] = -1;
            }
            else {
                diff[temp] = d;
                lastPosi[temp] = i;
            }
        }
    }
    int count=0;
    for (int i=1; i<100001; i++){
        if (lastPosi[i] != -1 && diff[i] != -1){
            count++;
        }
    }
    cout << count << "\n";
    if (count != 0){
        for (int i=1; i<100001; i++){
            if (lastPosi[i] != -1 && diff[i] != -1){
                cout << i << " " << diff[i] << "\n";
            }
        }
    }
    return 0;
}
