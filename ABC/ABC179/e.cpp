//
// Created by 原田 on 2021/07/09.
//


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
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

#include <iostream>
using namespace std;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n,x,m;
    cin>>n>>x>>m;

    map<ll,int>mp;
    vl log;
    log.push_back(-1);
    log.push_back(x);
    vl log_sum;
    mp[x] = 1;
    log_sum.push_back(0);
    log_sum.push_back(x);

    for (int i = 2; i <= n; ++i) {
        ll next = modpow(log[i-1],2,m);
        if(mp[next] != 0){
            ll l = mp[next]-1;
            ll r = i -1;
            ll all_sum = log_sum[r] - log_sum[l];
            ll ans;
            if((n-r)%(r-l) == 0){
                ans = log_sum[r] + all_sum * (n-r)/(r-l);
            }else{
                ll amari = n - r;
                ll ko = amari / (r-l);
                ll nokori = amari % (r-l);
                ans = log_sum[r] + (all_sum * ko) + (log_sum[nokori + l] - log_sum[l]);
            }
            cout<<ans<<endl;
            return 0;
        }else{
            mp[next] = i;
            log.push_back(next);
            log_sum.push_back(log_sum[i-1]+next);
        }
    }
    cout<<log_sum[n]<<endl;

    return 0;
}
