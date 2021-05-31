#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        char ans[n];
        int x=k/2, change = 0;;
        
        for(int i=0; i<x; i++){
            map<char, int> freq;
            freq.clear();
            for(int j=0; j<n/k; j++){
                freq[s[k*j + i]]++;
                freq[s[n - k*j - i - 1]]++;
            }
            int max=0;
            char c;
            for(pair<char, int> f : freq){
                if(f.second>max){
                    c = f.first;
                    max = f.second;
                }
            }
            for(pair<char, int> f : freq){
                if(f.first != c){
                    change += f.second;
                }
            }
        }
        if(k%2!=0){
            map<char, int> freq;
            for(int i=0; i<n/k; i++){
                freq[s[(k/2)+(i*k)]]++;
            }
            int max=0;
            char c;
            for(pair<char, int> f : freq){
                if(f.second>max){
                    c = f.first;
                    max = f.second;
                }
            }
            for(pair<char, int> f : freq){
                if(f.first != c){
                    change += f.second;
                }
            }
        }
        cout << change << "\n";
    }
    return 0;
}
