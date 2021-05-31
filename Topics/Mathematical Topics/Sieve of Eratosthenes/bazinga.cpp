#include <iostream>
#include <vector>

using namespace std;

int n = 10527450;
vector<int> lp(n+1, 0), pr;
vector<int> spNum;
void sieve(){
    lp[1]= 1;
    for(int i = 2; i<=n; i++){
        if(!lp[i]){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; j++){
            lp[i*pr[j]] = pr[j];
        }
        int curr = i/lp[i];
        if(curr != 1 && lp[curr] == curr && lp[i] != lp[curr])  spNum.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    int t, k;
    cin >> t;
    while(t){
        t--;
        cin >> k;
        cout << spNum[k-1] << "\n";
    }
    return 0;
}

