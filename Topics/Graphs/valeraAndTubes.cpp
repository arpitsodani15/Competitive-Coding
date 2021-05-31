#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool isValid(int x, int y){
    if(x>n || x<1 || y>m || y<1)    return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    int x = k-1, y = (n*m) - (2*k) + 2;
    int i=1, j=1;
    bool left = false, right = true;
    for(int t=1; t<=x; t++){
        cout << 2 << " ";
        int count = 2;
        for(; count!=0; ){
            if(j>m && right){
                left = true;
                right = false;
                i++;
                j--;
            }
            if(j<1 && left){
                right = true;
                left = false;
                i++;
                j++;
            }
            cout << i << " " << j << " ";
            count--;
            if(right){
                j++;
            }
            else if(left){
                j--;
            }
        }
        cout << "\n";
    }
    cout << y << " ";
    int count = y;
    for(; count!=0; ){
        if(j>m && right){
            left = true;
            right = false;
            i++;
            j--;
        }
        if(j<1 && left){
            right = true;
            left = false;
            i++;
            j++;
        }
        cout << i << " " << j << " ";
        count--;
        if(right){
            j++;
        }
        else if(left){
            j--;
        }
    }
    return 0;
}