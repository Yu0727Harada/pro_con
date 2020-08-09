//
//
// Created on 2020/01/11.
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
    ll n;
    cin>>n;
    ll a1;
    ll a2;
    ll b1;
    ll b2;
    a1 = n;
    a2 = 1;

    b1 = n;
    b2 = 1;

    while (abs(b1-b2)!=0){
        if(lcm((a1+a2)/2,(b1+b2)/2)<n){
            b2 = (b1+b2)/2;
        }else if(lcm((a1+a2)/2,(b1+b2)/2)>n){
            b1 = (b1+b2)/2;
        }else if(lcm((a1+a2)/2,(b1+b2)/2)==n){
            cout<<(a1+a2)/2<<(b1+b2)/2<<endl;
            return 0;
        }
    }


}

