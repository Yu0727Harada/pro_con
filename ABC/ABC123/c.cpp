//
// Created on 2020/07/28.
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
    ll n;
    cin>>n;
    vector<ll>t(5);
    ll MIN = LINF;
    int MIN_index;
    for (int i = 0; i < 5; ++i) {
        cin>>t[i];
        if(MIN > t[i]){
            MIN = t[i];
            MIN_index = i;
        }
    }
    ll ans = (n + (MIN - 1)) / MIN;
    ans += MIN_index - 0;
    ans += 4 - MIN_index;
    cout<<ans<<endl;

    return 0;
}

//律速反応
/*
 * https://atcoder.jp/contests/abc123/tasks/abc123_c
AtCoder 社は成長し、2028 年になってついに
6
つの都市 (都市
1
,
2
,
3
,
4
,
5
,
6
) からなる AtCoder 帝国を作りました！

AtCoder 帝国には
5
つの交通機関があります。

電車：都市
1
から
2
まで
1
分で移動する。
1
つの電車には
        A
人まで乗ることができる。
バス：都市
2
から
3
まで
1
分で移動する。
1
つのバスには
        B
人まで乗ることができる。
タクシー：都市
3
から
4
まで
1
分で移動する。
1
つのタクシーには
        C
人まで乗ることができる。
飛行機：都市
4
から
5
まで
1
分で移動する。
1
つの飛行機には
        D
人まで乗ることができる。
船：都市
5
から
6
までを
1
分で移動する。
1
つの船には
        E
人まで乗ることができる。
それぞれの交通機関は、各整数時刻 (
0
,
1
,
2
,
3
,
.
.
.
) に、都市から出発します。
いま、
N
        人のグループが都市
1
におり、全員都市
6
まで移動したいです。全員が都市
6
に到着するまでに最短で何分かかるでしょうか？
なお、乗り継ぎにかかる時間を考える必要はありません。*/

