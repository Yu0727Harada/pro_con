//
// Created on 2020/07/31.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>road(n,vector<pair<ll,ll>>(n,{LINF,-10}));//first->distance,second->time
    for (int i = 0; i < m; ++i) {
        int s,t;
        ll d,time;
        cin>>s>>t>>d>>time;
        s--;t--;
        road[s][t] = {d,time};
        road[t][s] = {d,time};
    }
    vector<vector<pair<ll,ll>>>dp(1<<n,vector<pair<ll,ll>>(n,{LINF,0}));//first->distance,second->rout
    dp[0][0] = {0,1};
    for (int S = 1; S < (1<<n); ++S) {
        for (int i = 0; i < n; ++i) {
            if(S & (1<<i)){
                int prev_S = S & ~(1<<i);
                for (int j = 0; j < n; ++j) {
                    if(road[j][i].second >= dp[prev_S][j].first + road[j][i].first){
                        if(dp[S][i].first > dp[prev_S][j].first + road[j][i].first){
                            dp[S][i] = {dp[prev_S][j].first + road[j][i].first,dp[prev_S][j].second};
                        }else if(dp[S][i].first == dp[prev_S][j].first + road[j][i].first){
                            dp[S][i] = {dp[prev_S][j].first + road[j][i].first,dp[S][i].second + dp[prev_S][j].second};
                        }
                    }
                }
            }
        }
    }
    ll ans_time = dp[(1<<n)-1][0].first;
    ll ans_way = dp[(1<<n)-1][0].second;

    if(ans_time == LINF){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<ans_time<<" "<<ans_way<<endl;

    return 0;
}

/*https://atcoder.jp/contests/s8pc-1/submissions/15546076*/
/*
E869120は, セールスマンである。だから, すべての建物を
1
度ずつ通って店に戻ってこなければならない。

E869120の住む街には, 建物が
        N
個あり, 道路が
        M
本ある。建物の番号は1-indexedでつけられており, 店は建物
1
とする。

また, 道路
        i
は建物
        s
i
        と建物
t
        i
を結んでいて, 距離は
        d
i
        である。

しかし, その街は不審者対策として一定の時間を過ぎると道路を閉鎖する。

道路
        i
は, E869120が出発してから時間
        t
i
        m
e
        i
経つと道路が閉鎖される。

だから, その道路を通る際, 時間
        t
i
        m
e
        i
以内に道路を通り終えなければならない。

そのとき, E869120は次のようなことを考えた。

「最短時間で戻ってくる方法の総数はどのくらいあるのだろう？」

そこで, 優秀なプログラマーであるあなたにプログラムを作ってもらうことになりました。

最短経路と, 最短時間で戻ってくる方法の総数を求めなさい。ただし, E869120は時間
1
につき距離
1
進む。また, 道路は双方向に移動可能である。

*/
