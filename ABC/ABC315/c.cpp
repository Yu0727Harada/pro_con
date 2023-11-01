//
// Created on 2023/08/19.
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
    int n;
    cin>>n;

    map<int,multiset<ll>>mp;

    for (int i = 0; i < n; ++i) {
        ll f,s;
        cin>>f>>s;
        mp[f].insert(-s);
    }

    vl dis_li;
    ll same_ans = -LINF;
    for(auto ice:mp){
        auto it = ice.second.begin();
        dis_li.push_back(*it);
        if(ice.second.size() >= 2){
            ll one = *it;
            it++;
            ll two = *it;
            chmax(same_ans,(one + (two / 2)) * -1);
        }
    }
    ll ans = -LINF;
    if(dis_li.size() >= 2){
        sort(all(dis_li));
        ans = (dis_li[0] + dis_li[1]) * -1;
    }
    cout<<max(ans,same_ans)<<endl;

    return 0;
}
