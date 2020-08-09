//
// Created on 2020/02/16.
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

int main() {
    ll ans = LINF;
    ll max_v =1e6+10;

    vector<ll>dp(max_v);
    for (ll k = 0; k < max_v; ++k) {
        dp[k]=k;
    }

    ll i = 10;
    while (i<=max_v){
        for (ll j = i; j < max_v; ++j) {
            dp[j] = min(dp[j],1+dp[j-i]);
        }
        i *= 10;
    }
    ll n;
    cin>>n;
    for (ll l = n; l < max_v; ++l) {
        ans = min(dp[l]+dp[l-n],ans);
    }

    cout<<ans<<endl;
}
