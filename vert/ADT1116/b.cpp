//
// Created by yu on 2023/11/16.
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
    vi va(n,0);
    for (int i = 0; i < k; ++i) {
        int a;
        cin>>a;
        a--;
        va[a] = 1;
    }
    vector<pair<ll,ll>> light;
    vector<pair<ll,ll>> dark;
    for (int i = 0; i < n; ++i) {
        ll x,y;
        cin>>x>>y;
        if(va[i]) {
            light.push_back({x, y});
        }else {
            dark.push_back({x,y});
        }
    }

    ll max_l = 0;

    vector<ll>distance(dark.size(),LINF);

    for (int i = 0; i < light.size(); ++i) {
        for (int j = 0; j < dark.size(); ++j) {
            ll tmp_l = ((dark[j].first - light[i].first) * (dark[j].first - light[i].first)) + ((dark[j].second - light[i].second) * (dark[j].second - light[i].second));

            chmin(distance[j],tmp_l);
        }
    }

    for (int i = 0; i < dark.size(); ++i) {
        chmax(max_l,distance[i]);
    }
    double ans = sqrt(max_l);
    printf("%.10f\n", ans);

    return 0;
}
