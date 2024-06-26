//
// Created by yu on 2023/12/20.
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
    ll n,m,t;
    cin>>n>>m>>t;
    vi a(n,0);
    for (ll i = 1; i < n; ++i) {
        cin>>a[i];
    }
    vi bunus(n,0);
    for (ll i = 0; i < m; ++i) {
        ll x,y;
        cin>>x>>y;
        x--;
        bunus[x] = y;
    }

    ll now_t = t;
    bool ok = true;
    for (ll i = 1; i < n; ++i) {
        if(now_t - a[i] <= 0){
            ok = false;
        }else{
            now_t = now_t - a[i];
            now_t += bunus[i];
        }
    }
    if(ok){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
