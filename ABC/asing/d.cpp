//
// Created on 2020/07/11.
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


int bit_count(int i){
    //数字iを二進数表記にした際の1の数を調べる
    return __builtin_popcount(i);
}

int solve(int i){
    if(i == 0) return 0;
    return solve(i%bit_count(i))+1;
}

int main() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    int x0_cnt = 0;
    vector<int>x(n);
    for (int j = 0; j < n; ++j) {
        x[j] = s[j] - '0';
        x0_cnt += x[j];
    }
    reverse(all(x));
    vector<int>ans(n);

    for (int b = 0;b < 2; ++b) {
        int pc;
        if(b == 0) pc = x0_cnt + 1;
        else  pc = x0_cnt - 1;
        if(pc <= 0) continue;
        ll x0_mod = 0;
        int r = 1;
        for (int j = 0; j < n; ++j) {
            x0_mod = (x0_mod + (r * x[j]))% pc;
            r = (r * 2) % pc;
        }
        r = 1;
        for (int k = 0; k < n; ++k) {
            if(x[k] == b){
                ll now;
                if(b==0){
                    now = (x0_mod + r) % pc;
                }else{
                    now = (x0_mod - r)% pc;
                    if(now < 0)now += pc;
                }
                ans[k] = solve(now) + 1;
            }
            r = (r * 2) % pc;
        }
    }
    reverse(all(ans));
    for (int i = 0; i < n; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}

/*
 * D - Anything Goes to Zero

問題文
popcount(n)をnを2進表記したときの 1 の個数とします。 例えば、
popcount(3)=2,popcount(7)=3,popcount(0)=0 です。

f(n) を、「nをpopcount(n)で割ったあまりに置き換える」という操作を繰り返した際に
nが0になるまでの操作回数とします(この問題の制約下で
nが有限回の操作後に必ず0 になることが証明できます)。

以下は
n=7の例で、2回の操作でnが0になります。
popcount(7)=3なので、7を3で割ったあまりである1に置き換えます。
popcount(1)=1なので、
1 を 1 で割ったあまりである 0 に置き換えます。2 進表記で N 桁の整数 X が与えられます。
1≤i≤N を満たす整数 i について、X の上から i 桁目のビットを反転した整数を Xi とします。
f(X1),f(X2),…,f(XN)を求めてください。

制約
1≤N≤2×10 5X は 2 進表記で N 桁の(先頭の桁が 1 とは限らない)整数

https://atcoder.jp/contests/aising2020/tasks/aising2020_d

二進数の変換は途中でMODをとっていいならMODをとりながらやれば大きい桁でも大丈夫。
ビットを１つ立てるというのはその桁の2のX累乗を足し引きすれば高速にO（1）で求めることができる。
Popcountはx＋1、xー1の2種類しかないので、事前にこれらのMODを計算しておく。
0で割らないように気を付ける。
POW関数は遅いので使わないようにする。
 * */