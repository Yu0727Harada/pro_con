//
// Created on 2020/07/30.
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int v,e;
    cin>>v>>e;
    vector<vector<int>>g(v,vector<int>(v,INF));
    for (int i = 0; i < e; ++i) {
        int s,t,d;
        cin>>s>>t>>d;
        g[s][t] = d;
    }
    int ans = INF;
    for (int start = 0; start < v; ++start) {//全ての頂点から始めるパターンも調べる
        vector<vector<int>>dp((1<<v) + 10,vector<int>(v,INF));
        dp[0][start] = 0;//まだどこにも移動していない状態で初めの頂点にいる場合は0
        for (int s = 1; s < (1<<v); ++s) {//全ての状態について調べる
            for (int i = 0; i < v; ++i) {
                if(s & (1<<i)){//全ての頂点について集合に含まれているか調べる
                    //i番目が集合sに含まれている時
                    for (int j = 0; j < v; ++j) {
                        int p_s = s & ~(1<<i);//この集合に至る前の集合（頂点iにつく一歩手前なのでi番目のフラグを消す
                            chmin(dp[s][i],dp[p_s][j] + g[j][i]);//一個手前の集合の全ての頂点から今のiにいくまでのコスト（INFで初期化するのでjが前の集合になくてもOK

                    }
                }
            }
        }
        chmin(ans,dp[(1<<v)-1][start]);
    }

    if(ans >= INF)ans = -1;
    cout<<ans<<endl;

}
