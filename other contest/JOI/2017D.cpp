//
// Created on 2020/08/07.
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
    vector<vector<int>>toys(m,vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        int k;
        cin>>k;
        k--;
        toys[k][i] = 1;
        for (int j = 0; j < m; ++j) {
            toys[j][i] = toys[j][i-1] + toys[j][i];
        }
    }
    vector<int>dp(1<<m,INF);
    dp[0] = 0;
    for (int S = 0; S < (1<<m) - 1; ++S) {
        for (int j = 0; j < m; ++j) {
            if(S & (1<<j))continue;
            int l = 0;
            for (int k = 0; k < m; ++k) {
                if(S & (1<<k)){
                    l += toys[k][n];
                }
            }
            int r = l + toys[j][n];
            int change = 0;
            for (int k = 0; k < m; ++k) {
                if(j == k)continue;
                change += toys[k][r] - toys[k][l];
            }
            int next_S = S | (1<<j);
            chmin(dp[next_S] , dp[S] + change);
        }
    }
    cout<<dp[(1<<m)-1]<<endl;

    return 0;
}
/*

ある JOI 関係者は，おもちゃ屋で働いている．今日は，店内にあるぬいぐるみコーナーの整理をすることになった．

ぬいぐるみコーナーの棚には，
N
        個のぬいぐるみが左から右に一列に並べられている．棚は仕切りにより
        N
個の区画に区切られており，
1
つの区画に
1
個のぬいぐるみを置く．このおもちゃ屋は合計
        M
種類のぬいぐるみを売っており，それぞれ
1
から
        M
までの番号が付けられている．棚に並べられた
        N
個のぬいぐるみは，それぞれこの
        M
種類のうちのいずれかである．また，それぞれの種類のぬいぐるみは，少なくとも
1
個は存在する．

見栄えを良くするため，同じ種類のぬいぐるみが全て連続して棚に置かれるように，ぬいぐるみを並べ替えたい．次のような方法で，ぬいぐるみを並べ替えることにした．

N
        個のぬいぐるみのうちいくつかを選び，棚から取り出す．取り出さなかったぬいぐるみの位置は動かさない．
取り出したぬいぐるみを，好きな順に棚の空いている区画に戻していく．
並べ替えた後，同じ種類のぬいぐるみが全て連続して棚に置かれていなければならない． 並べ替えるために取り出すぬいぐるみの個数の最小値を求めるプログラムを作成せよ．

入力
        入力は
1
+
N
        行からなる．

1
行目には
2
個の整数
        N
,
        M
        (
                1
≦
N
≦
100000
,
1
≦
M
≦
20
)
が空白を区切りとして書かれており，ぬいぐるみが
        N
個あり，種類が
        M
種類あることを表す．

続く
        N
行のそれぞれには，
1
以上
        M
以下の整数が書かれている．
N
        行のうちの
i
        行目
        (
                1
≦
i
≦
N
)
に書かれた整数は，棚の左から
        i
番目の区画に置かれたぬいぐるみの種類を表す．各種類について，少なくとも
1
個のぬいぐるみが存在していることが保証される．
*/
