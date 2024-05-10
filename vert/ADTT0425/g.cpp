//
// Created by yu on 2024/04/25.
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
    int n,q;
    cin>>n>>q;
    vl a(n+2);
    vl a_sum(n+2,0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];

    }
    a[n + 1] = LINF;
    sort(all(a));
    for (int i = 1; i <= n; ++i) {
        a_sum[i] = a_sum[i - 1] + a[i];
    }
    for (int i = 0; i < q; ++i) {
        ll x;
        cin>>x;
        int ok = 0;
        int ng = n + 2;
        while(ng - ok > 1){
            int mid = (ok + ng)/2;
            if(a[mid] > x){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        ll ans = 0;
        ans += x * ok - a_sum[ok];
        ans += (a_sum[n] - a_sum[ok]) - (x * (n - ok));
        cout<<ans<<endl;

    }
    return 0;
}
