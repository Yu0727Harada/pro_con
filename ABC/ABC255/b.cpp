//
// Created on 2022/06/11.
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

    int n,k;
    cin>>n>>k;

    vl a(n,0);
    for (int i = 0; i < k; ++i) {
        int t;
        cin>>t;
        t--;
        a[t] = 1;
    }
    vector<pair<ll,ll>>b;
    vector<pair<ll,ll>>c;
    for (int i = 0; i < n; ++i) {
        if(a[i] == 1){
            ll x,y;
            cin>>x>>y;
            b.push_back({x,y});
        }else{
            ll x,y;
            cin>>x>>y;
            c.push_back({x,y});
        }

    }


    vl max_v(c.size(),LINF);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < c.size(); ++j) {

            ll dis = (c[j].first - b[i].first) * (c[j].first - b[i].first) + ((c[j].second - b[i].second)) * (c[j].second - b[i].second);
            max_v[j] = min(max_v[j],dis);
        }
    }
    ll ans = 0;
    for (int i = 0; i < c.size(); ++i) {
        chmax(ans,max_v[i]);
    }

    printf("%.10f\n", sqrt((double)ans));

    return 0;
}
