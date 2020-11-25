//
// Created on 2020/11/08.
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
    vector<ll>a(n);
    vector<ll>sum(2 * n+4,0);

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1]+a[i-1];
    }
    for (int i = n+1; i < 2*n+1; ++i) {
        sum[i] = sum[i-1]+a[i-n-1];
    }

    ll ans = LINF;



    for (int i = 1; i <= n; ++i) {//一番左を選ぶ
        //一番右 i+n

        for (int j = 0; j < n; ++j) {
            ll x = sum[i+n-1] -sum[i+j];//選んだ中での一番左
            ll y = sum[i+j] - sum[i-1];
            chmin(ans,abs(x-y));
        }
    }
    cout<<ans<<endl;
    return 0;
}
