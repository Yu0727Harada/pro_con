//
// Created on 2020/07/01.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    vector<pair<ll,ll>>balloon(n);
    for (int i = 0; i < n; ++i) {
        ll h,s;
        cin>>h>>s;
        balloon[i] = {h,s};
    }

    ll ok = LINF;
    ll ng = -1;
    ll mid = (ok + ng)/2;
    while(abs(ok-ng) != 1){
        vector<ll>limit(n);
        for (int i = 0; i < n; ++i) {
            ll b = balloon[i].first;
            ll a = balloon[i].second;
            if(mid - b < 0){
                limit[i] = -1;
            }else{
                limit[i] = (mid - b) / a;
            }
        }
        sort(all(limit));
        bool frag = true;
        for (ll j = 0; j < n; ++j) {
            if(limit[j] < j){
                frag =false;
            }
        }
        if(frag){
            ok = mid;
            mid = (ok + ng)/2;
        }else{
            ng = mid;
            mid = (ok + ng)/2;
        }
    }

    cout<<ok<<endl;
    return 0;
}

/*
 最初にこの高さで割ることができるか？を考えて貪欲ほうでとく。この高さを二分探索で縮めて行ってとく。負の数の割り算には注意


 高橋君は最近、射撃にハマっている。

高橋君は
N
 個の風船すべてを射撃で割り、得られる得点をできるだけ小さくする競技に参加している。

風船には
1
 から
N
 までの番号が付けられていて、風船
i
(
1
≦
i
≦
N
)
 は競技開始時に高度
H
i
 のところにあり、
1
 秒経過するにつれて高度が
S
i
 だけ増加する。

高橋君は競技開始時に
1
 個風船を割ることができ、そこから
1
 秒ごとに
1
 個の風船を割ることができる。どの順番で風船を割るのかは高橋君が自由に決定できる。

どの風船についても、その風船を割ることによるペナルティが発生する。ペナルティはその風船が割られたときの高度と等しい整数値となる。高橋君が最終的に得る得点は
N
 個の風船のペナルティのうちの最大値となる。

高橋君が得ることのできる得点として考えられる最小値を求めよ*/