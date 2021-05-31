#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
 
    if (it != v.end()) {
        int index = it - v.begin();
        return index;
    }
    else 
        return -1;
}

int main() {
    int n, m, check;
    scanf("%d %d %d", &n, &m, &check);
    vector<vector<int>> data;
    for(int i=0; i<n; i++){
        vector<int> line;
        for(int j=0; j<m; j++){
            int temp;
            scanf("%d ", &temp);
            line.push_back(temp);
        }
        data.push_back(line);
    }
    

    return 0;
}
