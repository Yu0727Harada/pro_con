//
// Created by 原田 on 2021/10/12.
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

    vector<pair<ll,ll>> sc;//time,value
    for (int i = 0; i < n; ++i) {
        ll a,b;
        cin>>a>>b;
        sc.push_back({a,+1});
        sc.push_back({a + b,-1});
    }
    sort(all(sc));

    map<int,int>mp;
    int cnt = 0;
    ll day = 0;
    for (int i = 0; i < sc.size(); ++i) {
        ll next_day = sc[i].first;
        ll next_v = sc[i].second + cnt;
        mp[cnt] += next_day - day;
        cnt = next_v;
        day = next_day;

    }

    for (int i = 1; i <= n; ++i) {
        cout<<mp[i]<<endl;
    }

    return 0;
}

//あるオンラインゲームがあり、 N 人のプレイヤーが登録しています。
//サービス開始日から 10100 日を迎えた今日、 開発者である高橋君がログイン履歴を調べたところ、 i 番目のプレイヤーはサービス開始日を 1 日目として、 Ai​ 日目から Bi​ 日間連続でログインし、 それ以外の日はログインしていなかったことが判明しました。 すなわち、i 番目のプレイヤーはサービス開始日から、Ai​ , Ai​+1 , … , Ai​+Bi​−1 日目に、 かつそれらの日にのみログインしていたことが分かりました。
//1≤k≤N をみたす各整数 k について、 サービス開始日から今日までの間で、ちょうど k 人がログインしていた日数を答えてください。

//すぬけプライムは毎日加入及び脱退ができるので、その日支払う料金が C 円を超えそうならサブスクリプションを利用し、超えないなら利用しないようにするのが最適です。
//そこで、
//s[i]= ( すぬけプライムを利用しない場合の i 日目に支払う料金 )
//を求めたいです。
//i の範囲が小さければ いもす法 で求めることができますが、今回は i の範囲が大きいので、なにか工夫する必要があります。
//例えば、以下のようにすれば良いです。
//
//ai​ 日目から bi​ 日目まで利用する ci​ 円のサービスを、
//
//ai​−1 日目と ai​ 日目 の間に料金が ci​ 円上がるイベントが起こる
//bi​ 日目と bi​+1 日目 の間に料金が ci​ 円下がるイベントが起こる
//と言い換え、これらのイベントを時間でソートします。
//そして、 イベントを前から見ていきながら、今何日目を見ているのか と 現在の料金 の変数を更新していくと、 この問題を O(NlogN) で解くことができます。
//
//また、ai​ と bi​ を座標圧縮し、いもす法を適用できるようにする方法もあります。