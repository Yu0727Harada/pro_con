//
// Created on 2021/07/31.
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

    int n,m;
    cin>>n>>m;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vl b(m);
    for (int i = 0; i < m; ++i) {
        cin>>b[i];
    }
    sort(all(b));

    ll ans = LINF;
    for (int i = 0; i < n; ++i) {

        int l = 0;
        int r = m - 1;
        int mid;
        while(r - l > 1){
            mid = (l + r) / 2;
            if(a[i] < b[mid]){
                r = mid;
            }else{
                l = mid;
            }
        }
        chmin(ans,abs(a[i] - b[r]));
        chmin(ans,abs(a[i]-b[l]));
    }

    cout<<ans<<endl;

    return 0;
}

