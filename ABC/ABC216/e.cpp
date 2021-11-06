
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
    ll n,k;
    cin>>n>>k;

    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    ll ok = 2 * INF + 1;
    ll ng = 1;
    ll mid;
    while(ok - ng > 1){
        mid = (ok + ng)/2;

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max((ll)0,a[i] - (mid - 1));
        }
        if(cnt > k){
            ng = mid;
        }else{
            ok = mid;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] >= ok){
            ans += ((a[i] - (ok - 1)) * (2 * ok + (a[i] - (ok - 1) - 1))) / 2;
            k -= a[i] - (ok - 1);
        }
    }
    int temp_cnt = 0;
    while(k > 0 && temp_cnt < n){
        ans += ok - 1;
        k --;
        temp_cnt ++;
    }

    cout<<ans<<endl;

    return 0;
}

/*
E - Amusement Park
問題文

        髙橋君は遊園地に遊びに行きました。
この遊園地には N 個のアトラクションがあり、i 個目のアトラクションの「楽しさ」の初期値は Ai​ です。

髙橋君が i 個目のアトラクションに乗ると、以下の現象が順番に起きます。

髙橋君の「満足度」に、i 個目のアトラクションの現在の「楽しさ」が加算される。
i 個目のアトラクションの「楽しさ」が、1 減少する。
髙橋君の「満足度」の初期値は 0 です。髙橋君はアトラクションに合計 K 回まで乗ることができます。
最終的な髙橋君の「満足度」の最大値はいくつですか？

なお、髙橋君の「満足度」はアトラクションに乗ること以外で変化しません。


「楽しさ」0 以下のアトラクションに乗ることは考えなくてよいです。

よって、問題は次のように言い換えられます。

数列 B=(1,2,…A1​,1,2,…A2​,…,1,2,…AN​) から K 個以下の要素を選ぶとき、合計の最大値はいくつか？

数列 B の長さが K 以下の時は単純に全ての合計が答えです。
以下では数列 B の長さは K を超えるとします。

B をソートして大きい順に K 個選べば良いですが、Ai​,K が大きいので工夫する必要があります。

二分探索を用いましょう。以下の判定問題を考えます。

数列 B に含まれる m 以上の値は K 個以下か？ ⋯(∗)

(∗) は m=1 のとき False で、 m=2×109+1 のとき True です。
また、(∗) は m に関して単調です。
さらに、(∗) は O(N) で解くことができます。

よって、 m に対して二分探索を使うことができ、(∗) を満たす最小の m を求めることができました。 (求めた最小の m を M とします。)

数列 B から K 個の要素を選ぶとき、

M 以上の要素を全て選ぶ
残り(K 個に満たない部分)は M−1 を選ぶ
        という選び方が明らかに最適です。

以上より、この問題を解くことができました。
計算量は O(Nlogmax(Ai​)) です。
 */