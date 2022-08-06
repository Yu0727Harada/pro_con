
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
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    sort(all(a));
    vl posi_a_sum(n+1);
    posi_a_sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        posi_a_sum[i + 1] = posi_a_sum[i] + a[i];
    }
    vl nega_a_sum(n + 1);
    nega_a_sum[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        nega_a_sum[i] = nega_a_sum[i + 1] + (INF - a[i]);
    }

    for (int i = 0; i < q; ++i) {
        ll x;
        cin>>x;

        int ok = -1;
        int ng = n;
        int mid;
        while(abs(ok - ng) > 1){
            mid = (ok + ng)/2;
            if(a[mid] <= x){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll r = ok;
        ok = -1;
        ng = n;
        mid;
        while(abs(ok - ng) > 1){
            mid = (ok + ng)/2;
            if(a[mid] < x){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll l = ng;
        ll ans = 0;
        ans += posi_a_sum[n] - posi_a_sum[r + 1] - ((n - (r + 1)) * x);
        ans += nega_a_sum[0] - nega_a_sum[l] - (l * (INF - x));
        cout<<ans<<endl;
    }

    return 0;
}
