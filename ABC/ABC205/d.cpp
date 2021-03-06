//
// Created on 2021/06/13.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n,q;
    cin>>n>>q;

    vl a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    a[n + 1] = LINF + 1;
    sort(all(a));


    for (int i = 0; i < q; ++i) {
        ll k;
        cin>>k;

        ll ok = n + 1;
        ll ng = 0;
        ll mid = (ok + ng)/2;
        while(ok - ng != 1){
            mid = (ok + ng)/2;
            if(a[mid] - (mid) >= k){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        ll ans = a[ng] + (k - (a[ng] - ng));
        cout<<ans<<endl;

    }

    return 0;
}
