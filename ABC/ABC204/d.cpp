//
// Created by 原田 on 2021/06/09.
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



int main() {
    int n;
    cin>>n;

    vi t(n+1);
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>t[i];
        all += t[i];
    }
    vvi dp(n+1,vi(100005,0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 100005; ++j) {
            if(dp[i-1][j])dp[i][j + t[i]] = 1;//choose
            if(dp[i-1][j])dp[i][j] = 1;//not
        }
    }

    int l;
    if(all % 2 == 0){
        l = all / 2;
    }else{
        l = (all + (2 - 1)) / 2;
    }

    for (int i = l; i < 100005; ++i) {
        if(dp[n][i]){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
