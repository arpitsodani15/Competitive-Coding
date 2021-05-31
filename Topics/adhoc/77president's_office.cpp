#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<int> row, col;
    string mat[n];
    for (int i=0; i<n; i++){
        cin >> mat[i];
    }
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==c){
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    set<char> near;
    if(n==1 && m==1){
        cout << 0;
        return 0;
    }
    for (int j=col.front(); j<col.back()+1; j++){
        if(row.front() != 0 && mat[row.front()-1][j] != '.'){
            near.insert(mat[row.front()-1][j]);
        }
        if(row.back() != n-1 && mat[row.back()+1][j] != '.'){
            near.insert(mat[row.back()+1][j]);
        }
    }
    for (int i=row.front(); i<row.back()+1; i++){
        if(col.front() != 0 && mat[i][col.front()-1] != '.'){
            near.insert(mat[i][col.front()-1]);
        }
        if(col.back() != m-1 && mat[i][col.back()+1] != '.'){
            near.insert(mat[i][col.back()+1]);
        }
    }
    printf("%d", near.size());
    return 0;
}
