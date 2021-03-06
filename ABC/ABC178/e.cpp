//
// Created on 2020/09/13.
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
    int n;
    cin>>n;
    vector<ll>a;
    vector<ll>b;
    for (int i = 0; i < n; ++i) {
        ll x,y;
        cin>>x>>y;
        ll t_a = x- y;//斜め上にいく座標
        ll t_b = x+y;//斜め下の座標
        a.push_back(t_a);
        b.push_back(t_b);
    }
    sort(all(a));
    sort(all(b));
    ll ans = max(abs(a[n-1]-a[0]),abs(b[n-1]-b[0]));
    //マンハッタン距離の最大値はaとbそれぞれの最大値のmax。aとbの差の最大値はそれぞれの最小値と最大値の差
    cout<<ans<<endl;

    return 0;
}
//マンハッタン距離