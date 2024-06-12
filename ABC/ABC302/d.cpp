
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

vl b;

int bi_s(ll a_v, ll d){
    int ok = 0;
    int ng = b.size();
    int mid;
    while(ng - ok > 1){
        mid = (ok + ng) / 2;
        if(b[mid] <= a_v + d){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n,m;
    cin>>n>>m;
    ll d;
    cin>>d;
    vl a(n);
    b.resize(m);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
        int j = bi_s(a[i],d);
        if(a[i] - d <= b[j] && b[j] <= a[i] + d){
            chmax(ans,b[j] + a[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
