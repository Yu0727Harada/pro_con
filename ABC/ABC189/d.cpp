//
// Created by 原田 on 2021/09/27.
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

    vector<string>vs(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>vs[i];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(2,0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i <= n; ++i) {
        if(vs[i] == "AND"){

            //trueを選ぶ
            dp[i][1] += dp[i - 1][1];
            dp[i][0] += dp[i - 1][0];

            //falseを選ぶ
            dp[i][0] += dp[i - 1][0];
            dp[i][0] += dp[i - 1][1];
        }else{
            //trueを選ぶ
            dp[i][1] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][0];

            //falseを選ぶ
            dp[i][1] += dp[i - 1][1];
            dp[i][0] += dp[i - 1][0];
        }
    }

    cout<<dp[n][1]<<endl;

    return 0;
}
//N 個の文字列 S1​,…,SN​ が与えられます。各文字列は AND または OR です。
//
//値が True または False であるような N+1 個の変数の組 (x0​,…,xN​) であって、 以下のような計算を行った際に、yN​ が True となるようなものの個数を求めてください。
//
//y0​=x0​
//i≥1 のとき、Si​ が AND なら yi​=yi−1​∧xi​、Si​ が OR なら yi​=yi−1​∨xi​
//        a∧b は a と b の論理積を表し、a∨b は a と b の論理和を表します。