//
// Created on 2020/07/25.
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
    vector<ll>g(n+1,0);
    g[0] = 1000;
    vector<ll>p(n+1);
    for (int j = 1; j <= n; ++j) {
        cin>>p[j];
    }
    for (int i = 1; i <= n; ++i) {
        ll kabu_num = g[i-1]/p[i];
        ll cash = g[i-1]%p[i];

        for (int j = i; j <= n; ++j) {
            if(g[j] < (kabu_num * p[j])+cash) g[j] = kabu_num * p[j]+cash;
        }
    }

    cout<<g[n]<<endl;
    return 0;
}

/*
 *
 *https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
 *
 * 一日の内に全て株を買ってN日目に全て売るという遷移でDPをする
 * 数値の範囲がlong longなのに注意すること
 *
 *
 * M 君は億万長者を目指して、明日から
N
 日間は投資で稼ごうと考えました。現在の彼の所持金は
1000
 円であり、株は持っていません。なお、M 君の住んでいる国で発行されている株は一種類です。

彼は全国に知られる未来予知能力者であり、今後
N
 日間の株価が以下のようになることをすでに知っています。

1
 日目の株価は
A
1
 円、
2
 日目の株価は
A
2
 円、・・・、
N
 日目の株価は
A
N
 円
i
 日目には、その時点で所持する金と株の範囲内で、M 君は次の取引を何回でも行えます。何も取引しない日があっても構いません。

株式購入：
A
i
 円を支払って、
1
 株を受け取る。
株式売却：
1
 株を売却し、
A
i
 円を受け取る。
さて、M 君がうまく取引を行ったとき、彼の最終的な所持金は最大でいくらになるでしょうか？


 * */