//
// Created on 2020/01/10.
//


#include <bits/stdc++.h>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int solve(){
    int N;
    cin>>N;
    vector<ll>s;
    bool positive = false;
    bool all_pisitive = true;
    ll temp2 = 0;
    for (int i = 0; i < N; ++i) {
        ll temp;
        cin>>temp;
        if (temp<=0){
            all_pisitive = false;
            if(!positive){
                s.push_back(temp);
                positive = false;
            }
            else{
                s.push_back(temp2);
                temp2 = 0;
                s.push_back(temp);
                positive = false;
            }
        }
        if (temp > 0){
            temp2 += temp;
            positive = true;
        }

    }
    if (temp2 != 0) s.push_back(temp2);
    if(all_pisitive){
        cout<<"YES"<<endl;
        return 0;
    }
    auto sum = accumulate(all(s),0LL);
    //0LL long long,0 int,0.0 double
    ll adel = 0;

    for (int j = 0; j < s.size(); ++j) {
        for (int i = j+1; i <= s.size(); ++i) {
            if(j==0 && i ==s.size())continue;
            adel = max(adel,accumulate(s.begin()+j,s.begin()+i,0LL));
        }
    }
    if (sum<=adel){
        cout<<"NO"<<endl;
        return 0;
    }else{

        cout<<"YES"<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

}
