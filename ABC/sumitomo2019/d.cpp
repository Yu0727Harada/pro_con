#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
using gragh = vector<vector<int>>;


int main() {
    int N;
    cin>>N;
    string S;
    cin>>S;
    int ans = 0;

    for (int i = 0; i < 1000; ++i) {
        string t;
        int x = i;
        for (int j = 0; j < 3; ++j) {
            t += to_string(0 + x%10);
            x /= 10;
        }
        int ti = 0;
        for (int k = 0; k < N; ++k) {
            if(S[k]==t[ti]){
                ti++;
                if(ti == 3 ){
                    break;
                }
            }
        }
        if (ti == 3){
            ans ++;
        }
    }

    cout<<ans<<endl;



}
