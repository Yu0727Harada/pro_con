//
// Created on 2021/12/19.
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
    int h , w;
    cin>>h>>w;

    vvi g(h,vi(w));
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#')g[i][j] = -1;
            else g[i][j] = 0;
        }
    }

    vvi dp(h,vi(w,-1));

    int ans = 0;

    dp[0][0] = 1;
    chmax(ans,dp[0][0]);
    for (int i = 1; i < w; ++i) {
        if(dp[0][i - 1] != -1 && g[0][i] == 0){
            dp[0][i] = dp[0][i - 1] + 1;
            chmax(ans,dp[0][i]);
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(g[i][j] == 0){
                if(j == 0){
                    if(dp[i - 1][j] != -1){
                        chmax(dp[i][j],dp[i - 1][j] + 1);
                        chmax(ans,dp[i][j]);

                    }
                }else {
                    if(dp[i - 1][j] != -1 && dp[i][j - 1] != -1){
                        chmax(dp[i][j], max(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                        chmax(ans, dp[i][j]);
                    }else if(dp[i - 1][j] != -1){
                        chmax(dp[i][j], (dp[i - 1][j] + 1));
                        chmax(ans, dp[i][j]);

                    }else if(dp[i][j - 1] != -1){
                        chmax(dp[i][j], dp[i][j - 1] + 1);
                        chmax(ans, dp[i][j]);
                    }
                    }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
