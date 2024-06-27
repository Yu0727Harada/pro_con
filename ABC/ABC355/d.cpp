
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

int ser_after(int target,vi list){
    int ok = list.size();
    int ng = 0;
    int mid;
    while(ok - ng > 1){
        mid = (ok + ng) / 2;
        if(list[mid] >= target){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ng;
}
int ser_before(int target,vi list){
    int ok = 0;
    int ng = list.size();
    int mid;
    while(ng - ok > 1){
        mid = (ok + ng) / 2;
        if(list[mid] > target){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}


int main() {
    ll n;
    cin>>n;
    vi l(n);
    vi r(n);
    for (int i = 0; i < n; ++i) {
        cin>>l[i];
        cin>>r[i];
    }

    sort(all(l));
    sort(all(r));
    ll ans = n * (n-1) / 2;
    ll j = 0;
    for (int i = 0; i < n; ++i) {
        while(r[j] < l[i]){
            j++;
        }
        ans -=j;
    }

    cout<<ans<<endl;
    return 0;
}
