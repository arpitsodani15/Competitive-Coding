#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

int distance (int x1, int y1, int x2, int y2){
    return ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
}

bool willFreeze (int x1, int y1, int heater[][3], int n){
    for(int i=0; i<n; i++){
        int dis = distance(x1, y1, heater[i][0], heater[i][1]);
        if(dis<=heater[i][2]*heater[i][2]){
            return false;
        }
    }
    return true;
}

int main() {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int n;
    cin >> n;
    int heater[n][3];
    for (int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin >> heater[i][j];
    int count = 0;
    for (int i=min(xa,xb); i<=max(xa,xb); i++){
        if(willFreeze(i,ya,heater,n))
            count++;
        if(willFreeze(i,yb,heater,n))
            count++;
    }
    for (int i=min(ya,yb)+1; i<=max(ya,yb)-1; i++){
        if(willFreeze(xa,i,heater,n))
            count++;
        if(willFreeze(xb,i,heater,n))
            count++;
    }
    cout << count;
    return 0;
}
