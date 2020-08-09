//
// Created on 2020/07/03.
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
    ll m;
    cin>>m;
    vector<ll>point;
    point.push_back(0);
    for (int i = 0; i < n; ++i) {
        ll t;
        cin>>t;
        point.push_back(t);
    }
    vector<ll>sum_point;
    for (int i = 0; i < point.size(); ++i) {
        for (int j = 0; j < point.size(); ++j) {
            sum_point.push_back(point[i] + point[j]);
        }
    }
    sort(all(sum_point));
    ll ans = 0;
    for (int k = 0; k < sum_point.size(); ++k) {

        ll ng = sum_point.size();
        ll ok = -1;
        ll mid = (ok + ng)/2;
        while(abs(ok - ng) != 1){
            if(sum_point[k] + sum_point[mid] > m){
                ng = mid;
                mid = (ok+ng)/2;
            }else{
                ok = mid;
                mid = (ok+ng)/2;
            }
        }
        if(ok >= 0) ans = max(sum_point[k]+sum_point[ok],ans);
    }
    cout<<ans<<endl;
    return 0;
}

/*
 *
 *
 *
あなたは以下のルールでダーツゲームをすることになった.
ダーツ
あなたは，矢を的(まと)に向かって 4 本まで投げることができる.必ず しも 4 本全てを投げる必要はなく，1 本も投げなくてもかまわない.的 は N 個の部分に区切られていて，各々の部分に点数 P1, · · · , PN が書か れている.矢が刺さった場所の点数の合計 S があなたの得点の基礎とな る.S があらかじめ決められたある点数 M 以下の場合は S がそのまま あなたの得点となる.しかし，S が M を超えた場合はあなたの得点は 0 点となる.
的に書かれている点数と M の値が与えられたとき，あなたが得ることのできる 点数の最大値を求めるプログラムを作成せよ.


今度は，「4 本の矢を投げる」ことを，「まず 2 本の矢をまとめて投げて，次に 2 本の矢をまとめて 投げる」と考えることにしよう.
矢を 2 本投げることで得られる点数は (N + 1)2 通り以下である.まず，下準備として，これらの可 能性をすべて調べてソートしておく.ソートした結果を Q1 􏰀 Q2 􏰀 · · · 􏰀 Qr とおく (r 􏰀 (N + 1)2 ). この下準備にかかる時間は O(N 2 log N ) である.
さて，最初の 2 本の矢の点数の合計が Qi であったと仮定しよう.残りの 2 本の矢(3 本目，4 本 目の矢)の最適な得点を求めるためには，
Qi + Qj 􏰀 M
をみたす j のうち，Qj が最も大きくなるものを求めればよい.このような j は二分探索により O(log N ) 時間で求めることができる.各 i (1 􏰀 i 􏰀 r) に対して最適な j を求めればよいので，全体 としてO(N2 logN)時間かかる.
下準備の時間も含めて，この解法では，全体で O(N 2 log N ) 時間かかる.
この問題の設定では N 􏰀 1000 なので，この方法であれば，すべてのデータに対して制限時間内 に正解を出力することができる.
 * */