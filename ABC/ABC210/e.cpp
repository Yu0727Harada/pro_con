//
// Created on 2021/07/17.
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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> ac;
    for (int i = 0; i < m; ++i) {
        ll a,c;
        cin>>a>>c;
        ac.push_back({c,a});
    }
    ll ans = 0;
    sort(all(ac));
    if(n % ac[0].second == 0){
        ans += ac[0].first * (n-2);
        bool find = false;
        for (int i = 1; i < m; ++i) {
            if(max(ac[i].second,ac[0].second) % min(ac[i].second,ac[0].second) != 0){
                ans += ac[i].first;
                find = true;
            }
        }
        if(find == false)ans = -1;
    }else{
        ans += ac[0].first * (n-1);
    }
    cout<<ans<<endl;
    return 0;
}

