//
// Created by 原田 on 2022/05/09.
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
    ll n,d;
    cin>>n>>d;
    vector<pair<ll,ll>>kabe(n);//{r,l}
    for (int i = 0; i < n; ++i) {
        ll l,r;
        cin>>l>>r;
        kabe[i]={r,l};
    }
    sort(all(kabe));
    int ans = 0;
    ll dist_l = 0;
    ll dist_r = 0;
    for (int i = 0; i < n; ++i) {
        if((kabe[i].second <= dist_l && dist_l <= kabe[i].first) || (kabe[i].second <= dist_r && dist_r <= kabe[i].first) ||(dist_l <= kabe[i].second && kabe[i].first <= dist_r))continue;
        else{
            dist_l = kabe[i].first;
            dist_r = kabe[i].first + d - 1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
