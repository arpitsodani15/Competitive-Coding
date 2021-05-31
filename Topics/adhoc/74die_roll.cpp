#include <iostream>
using namespace std;

int main() {
    int Y, W, D, count=0;
    cin >> Y >> W;
    for(int i=1; i<=6; i++){
        if(i>=Y && i>=W)
            count++;
    }
    if (count%2==0 && count%3!=0)
        printf("%d/%d", count/2, 3);
    else if(count%3==0 && count%2!=0)
        printf("%d/%d", count/3, 2);
    else if(count%6==0)
        printf("1/1");
    else
        printf("%d/%d", count, 6);
    return 0;
}
