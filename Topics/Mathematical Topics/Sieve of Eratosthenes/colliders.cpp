#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1e5;
    vector<int> lp(n+1, 0), pr;
    lp[1]= 1;
    for(int i = 2; i<=n; i++){
        if(!lp[i]){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    int n, m;
    cin >> n >> m;
    map<int, int> onFactors;
    for(int i=0; i<pr.size(); i++){
        onFactors.insert(pair<int, int>(pr[i], 0));
    }
    for(int i=0; i<m; i++){
        string s;
        char sign;
        cin >> sign >> s;
        int num = stoi(s);
        if(sign == '+'){
            int curr = num, check=1;
            while(curr != 1){
                if(onFactors[lp[curr]]==0){
                    check *= lp[curr];
                    curr = curr/lp[curr];
                }
            }
            if(check == num){
                cout << "Success\n";
            }
            else if(check == 1)
            // int check = 1;
            // for(int j=0; j<on.size(); j++){
            //     if(on[j] == num) {
            //         cout << "Already on\n";
            //         check = 0;
            //         break;
            //     }
            //     if(gcd(on[j], num) != 1) {
            //         cout << "Conflict with " << on[j] << "\n";
            //         check = 0;
            //         break;
            //     }
            // }
            // if(check == 1){
            //     cout << "Success\n";
            //     on.push_back(num);
            // }
        }
        else{
            // int check = 1;
            // for(int j=0; j<on.size(); j++){
            //     if(on[j] == num) {
            //         cout << "Success\n";
            //         check = 0;
            //         on.erase(on.begin()+j);
            //         break;
            //     }
            // }
            // if(check==1){
            //     cout << "Already off\n";
            // }
        }
    }
    return 0;
}
