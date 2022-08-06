//
// Created by 原田 on 2022/07/25.
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
//#include <atcoder/all>


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



int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    vl x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin>>x[i];
    }
    vi mp(n + 1,0);
    for (int i = 0; i < m; ++i) {
        int c,y;
       cin>>c>>y;
        mp[c] = y;
    }
    vector<vector<ll>>dp(n + 1,vl(n+10,-LINF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            chmax(dp[i + 1][0],dp[i][j]);
            chmax(dp[i + 1][j + 1],dp[i][j] + x[i + 1] + mp[j + 1]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        chmax(ans,dp[n][i]);
    }
    cout<<ans<<endl;


    return 0;
}
