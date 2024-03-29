//
// Created by 原田 on 2022/06/13.
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
    ll n,C;
    cin>>n>>C;
    vector<pair<int,pair<int,int>>>e;
    vl cost_l(n);
    for (int i = 0; i < n; ++i) {
        ll a,b,cost;
        cin>>a>>b>>cost;
        e.push_back({a,{i,1}});
        e.push_back({b + 1,{i,-1}});
        cost_l[i] = cost;
    }
    sort(all(e));
    ll ans = 0;
    ll all_cost = 0;
    ll now_date = 0;
    for (int i = 0; i < e.size(); ++i) {

        ll next_date = e[i].first;
        ll target_cost = cost_l[e[i].second.first];
        if(all_cost > C){
            //すぬけに加入すると安い時
            ans += (next_date - now_date) * C;
        }else{
            //個別に払うとき
            ans += (next_date - now_date) * all_cost;
        }
        if (e[i].second.second == 1) {
            //サービスを使う時
            all_cost += target_cost;
        } else {
            //サービスを使わない時
            all_cost -= target_cost;
        }
        now_date = next_date;

    }

    cout<<ans<<endl;
    return 0;
}
