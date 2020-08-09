//
// Created on 2020/02/22.
//

//#include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

const ll MAX =  1000000;//nCkのn,kの取りうるMAX
const int MOD = 1000000007;




long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//aのmod.mでの逆元を求める
long long modinv(long long a,long long m){
    long long b = m,u=1,v=0;
    while(b){
        long long t = a / b;
        a -= t * b ;
        swap(a,b);
        u -= t * v;
        swap(u,v);
    }
    u %= m;
    if (u < 0)u += m;
    return u;
}

//a / b mod. MOD を計算
long long div_mod(long long a,long long b){
    const int MOD = 1000000007;

    //aをMODで割ってからbの逆元をかける
    a %= MOD;
    return a * modinv(b,MOD)% MOD;
}

int main() {
    ll ans = 0;
    ll n;
    ll a;
    ll b;
    cin>>n>>a>>b;


    ans = modpow(2,n,MOD);
    ans --;

    vector<ll>com(max(a,b)+1);
    com[0]=1;
    ll k = 1;
    while (k <= max(a,b)){
        com[k] = div_mod(com[k-1]*(n+1-k),k);
        k+=1;
    }


    ans = mod(((ans%MOD)-(com[a]%MOD)),MOD);
    ans = mod(((ans%MOD)-(com[b]%MOD)),MOD);


    cout<<ans<<endl;
}

