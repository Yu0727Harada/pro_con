//
// Created on 2020/01/10.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a %b);
}
//2つの自然数の最大公約数を求める関数

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
//2つの自然数の最大公約数から最小公倍数を求める関数


int main() {
    ll A;
    ll B;
    ll ans;
    cin>>A;
    cin>>B;

    ans = lcm(A,B);
    cout<<ans<<endl;
}
