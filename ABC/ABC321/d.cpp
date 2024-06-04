
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

ll bit_s(ll target,vl li,int ok_p){
    int ok = ok_p;//a+bがP以下
    int ng = li.size();
    int mid;
    while(ng - ok > 1){
        mid = (ok + ng)/2;
        if(target >= li[mid]){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main() {
    ll n,m;
    ll p;
    cin>>n>>m;
    cin>>p;
    ll ans = 0;
    vl a(n);
    vl b(m + 1);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin>>b[i];
    }
    sort(all(b));
    sort(all(a));
    vl b_sum(m + 2,0);
    for (int i = 1; i <= m; ++i) {
        b_sum[i] = b_sum[i - 1] + b[i];
    }
    ll ok_pre = m;
    for (int i = 0; i < n; ++i) {
        ll ok_itr = ok_pre;
        while(a[i] + b[ok_itr] > p && ok_itr >= 0){
            ok_itr--;
        }
        if(ok_itr < 0)ok_itr = 0;
        ans += (ok_itr ) * a[i];
        ans += b_sum[ok_itr];
        ans += p * (m - (ok_itr ));
        ok_pre = ok_itr;
    }
    cout<<ans<<endl;

    return 0;
}
