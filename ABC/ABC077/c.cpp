//
// Created on 2020/06/25.
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
    vector<int>a(n);
    vector<int>b(n);
    vector<int>c(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto a_end = lower_bound(all(a),b[i]);
        auto c_star = upper_bound(all(c),b[i]);
        ll temp_ans = (a_end - a.begin()) * (c.end() - c_star);
        ans += temp_ans;
    }
    cout<<ans<<endl;

    return 0;
}
/*
C - Snuke Festival  /
今年もすぬけ祭の季節がやってきました。りんごさんは、まず手始めにすぬけ君召喚の儀式を執り行おうと思っています。 儀式には祭壇が必要で、祭壇は上部、中部、下部の3つのカテゴリーのパーツ
1つずつからなります。

祭壇の3カテゴリーのパーツがそれぞれN個ずつあります。
i個目の上部のパーツのサイズは
Ai、
i個目の中部のパーツのサイズは
B
        i
、
i
        個目の下部のパーツのサイズは
C
        i
です。

祭壇を作るにあたっては、中部のパーツのサイズは上部のパーツのサイズより真に大きく、下部のパーツのサイズは中部のパーツのサイズより 真に大きくなければなりません。逆に、この条件を満たす任意の
3
つのピースを組み合わせて祭壇を作ることができます。

りんごさんが作ることのできる祭壇は何種類あるでしょうか。ただし、
2
つの祭壇が異なるとは、上部、中部、下部に使われるピースのうち 少なくとも
1
つが異なることを言います。

 真ん中のパーツから見て真ん中のパーツの大きさより小さい上のパーツの個数を二分探索で、大きい下のパーツの個数を二分探索で数える


*/

