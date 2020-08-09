//
// Created on 2020/07/26.
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


using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    vector<int>m(n + 1);//{row,column}
    cin>>m[0]>>m[1];
    for (int i = 2; i <= n ; ++i) {
        int c;
        cin>>c>>m[i];
    }
    vector<vector<int>>dp(n + 1,vector<int>(n + 1,INF));//dp[i][j]はi番目の行列からj番目の行列を見た時に最小のスカラー積の回数
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;//１つしかないときはスカラー積の回数は0なので最初に初期化する
    }
    for (int l = 1; l + 1 <= n; ++l) {//iとjの差
        for (int i = 1; i + l <= n  ; ++i) {//１つ目の行列から順に見ていく。
            int j = i + l;//jはiに差を足したindex
            for (int k = i + 1; k <= j; ++k) {//kは境。全てのパターンを試して最小値で更新していく
                dp[i][j] = min(dp[i][k - 1] + dp[k][j] + m[i-1] * m[k-1] * m[j],dp[i][j]);
            }
        }
    }
    int ans = dp[1][n];
    cout<<ans<<endl;
    return 0;

}

/*まず行列の積というのの性質を考えて行列の数の情報を一次元でかんりできるようにする。状態をキーにしてDPするというよりかはフィボナッチ数列のように再帰的にとく
 * ijの差が0から順にループを回してとく
 * 行列１つだけの時は0
 * 差が1つの時はm[i-1]*m[k-1]*m[j]kは区切る境
 * 2はM1M2M3であるが計算の仕方はM1(M2M3)か(M1M2)M3
 * この時にkを2から3に移動させて最小値をとっていく。そうするとM1M2M3の最小値がもとまる。これを繰り返して再帰的に全体の最小値を求める
 * */
