//
// Created on 2019/12/12.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
using gragh = vector<vector<int>>;

int solve(){
    string S;
    cin>>S;
    int L=0;
    int R =0;
    int D = 0;
    int U = 0;

    for (int i = 0; i < S.size(); ++i) {
        if(S[i] == 'L') L++;
        else if(S[i] == 'R') R++;
        else if(S[i] == 'D') D++;
        else if(S[i] == 'U') U++;
    }
    int LR = min(L,R);

    int UD = min(U,D);

    if(UD == 0 && LR == 0) {
        cout<<0<<endl;
        return 0;
    }
    else if (UD == 0) {
        cout<<2<<endl;
        cout<<"LR"<<endl;
        return 0;
    }
    else if(LR == 0){
        cout<<2<<endl;
        cout<<"UD"<<endl;
        return 0;
    }
    else{
        cout<<(LR*2)+(UD*2)<<endl;
        for (int i = 0; i < LR; ++i) {
            cout<<'L';
        }
        for (int j = 0; j < UD; ++j) {
            cout<<'U';
        }
        for (int k = 0; k < LR; ++k) {
            cout<<'R';
        }
        for (int l = 0; l < UD; ++l) {
            cout<<'D';
        }
        cout<<endl;
        return 0;
    }

}

int main() {
    ll q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }

}
