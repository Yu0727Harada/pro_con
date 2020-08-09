//
// Created on 2020/06/20.
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
    int r;
    int c;
    cin>>r>>c;
    vector<vector<int>>senbei(c,vector<int>(r));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>senbei[j][i];
        }
    }
    int ans = 0;

    //n個の要素のbit全探索する
    int n = r;
    for (int bit = 0; bit < (1<<n); ++bit) {
        auto senbei_2 = senbei;
        for (int i = 0; i < n; ++i) {
            if(bit & (1<<i)){
                //i個目の要素にフラグが立っていた時の処理
                for (int j = 0; j < c; ++j) {
                    senbei_2[j][i] = (senbei_2[j][i] + 1) % 2;
                }
            }
        }
        int ans_t = 0;
        for (int k = 0; k < c; ++k) {
            auto sum = accumulate(all(senbei_2[k]),0);
            ans_t += max(sum,r-sum);
        }
        ans = max(ans,ans_t);
    }
    cout<<ans<<endl;
    return 0;
}
/*

IOI製菓では， 創業以来の伝統の製法で煎餅（せんべい）を焼いている． この伝 統の製法は， 炭火で一定時間表側を焼き， 表側が焼けると裏返して，
 炭火で一定時間裏側を焼くというものである． この伝統を守りつつ， 煎餅を機械で焼いている． この機械は縦R(1≦R≦10)行, 横C(1≦C≦10000)列の長方形状に
 煎餅を並べて焼く． 通常は自動運転で， 表側が焼けたら一斉に煎餅を裏返し裏側を焼く．

ある日， 煎餅を焼いていると， 煎餅を裏返す直前に地震が起こり何枚かの煎餅が裏返ってしまった． 幸いなことに炭火の状態は適切なままであったが， これ以上表 側を焼くと創業以来の伝統で定められている焼き時間を超えてしまい， 煎餅の表側が焼けすぎて商品として出荷できなくなる． そこで， 急いで機械をマニュアル操作に 変更し， まだ裏返っていない煎餅だけを裏返そうとした． この機械は， 横の行を何行か同時に裏返したり縦の列を何列か同時に裏返したりすることはできるが， 残念なことに， 煎餅を
1枚ごと裏返すことはできない．

裏返すのに時間がかかると， 地震で裏返らなかった煎餅の表側が焼けすぎて商品 として出荷できなくなるので， 横の何行かを同時に
1回裏返し， 引き 続き， 縦の何列かを同時に
1回裏返して， 表側を焼きすぎずに両面を 焼くことのできる煎餅， つまり， 「出荷できる煎餅」の枚数をなるべく多くするこ とにした． 横の行を
1行も裏返さない，あるいは， 縦の列を
1列も裏返さない場合も考えることにする． 出荷できる煎餅の枚数の最大値を出 力するプログラムを書きなさい．

地震の直後に， 煎餅が次の図のような状態になったとする． 黒い丸が表側が焼ける状態を， 白い丸が裏側が焼ける状態を表している．

https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
 */
