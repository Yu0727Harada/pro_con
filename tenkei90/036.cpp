//
// Created by 原田 on 2021/08/27.
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
    int q;
    cin>>q;

    ll min_a = LINF;
    ll max_a = -LINF;
    ll min_b = LINF;
    ll max_b = -LINF;
    vector<pair<ll,ll>>li(n);
    for (int i = 0; i < n; ++i) {
        cin>>li[i].first>>li[i].second;
        chmin(min_a,li[i].first + li[i].second);
        chmax(max_a,li[i].first + li[i].second);
        chmin(min_b,li[i].first - li[i].second);
        chmax(max_b,li[i].first - li[i].second);
    }

    while(q){
        q--;

        int t;
        cin>>t;
        t--;
        ll t_a = li[t].first + li[t].second;
        ll t_b = li[t].first - li[t].second;


        ll ret1 = abs(t_a - min_a);
        ll ret2 = abs(t_a - max_a);
        ll ret3 = abs(t_b - min_b);
        ll ret4 = abs(t_b - max_b);
        ll ans = max({ret1,ret2,ret3,ret4});



        cout<<ans<<endl;
    }


    return 0;
}
//
//二次元座標平面上に相異なる N 個の点 P[1], P[2], ..., P[N] があり、点 P[i] の座標は (x[i], y[i]) です。
//
//以下の Q 個のクエリを順に処理してください。
//・i (1 ≦ i ≦ Q) 番目のクエリでは、整数 q[i] が与えられるので、点 P[q[i]] と N 個の点の間のマンハッタン距離の最大値を出力する。
//・つまり、点 P[s] と P[t] のマンハッタン距離を dist(P[s], P[t]) とするとき、max⁡(dist(P[q[i]], P[1]), dist(P[q[i]], P[2]), …, dist(P[q[i]], P[N])) の値を出力する。
//
//
//【制約】
//・2 ≦ N ≦ 100000
//・1 ≦ Q ≦ 100000
//・|x[i]|, |y[i]| ≦ 10^9
//・(x[i], y[i]) ≠ (x[j], y[j]) [i ≠ j]
//・1 ≦ q[i] ≦ N
//・q[i] ≠ q[j] (i ≠ j)
//・入力はすべて整数

//dist_max
//マンハッタン距離
//45度回転する