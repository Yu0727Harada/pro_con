//
// Created by yu on 2024/04/26.
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
    ll l,r;
    cin>>l>>r;
    ll m = 0;
    ll itr = l;
    vector<pair<ll,ll>>ans;
    if(l == 0){
        ll div_2 = 0;
        for (ll i = 60; i >= 0; --i) {
            div_2 |= (1ull << i);
            if(r >= div_2){
                m++;
                ans.push_back({0,div_2});
                itr = div_2;
                break;
            }

            div_2 &= ~(1ull<<i);
        }
    }
    while (itr < r) {
        ll div_2 = 0;
        for (ll i = 60; i >= 0; --i) {
            div_2 |= (1ull << i);
            if(itr >= div_2 && itr % div_2 == 0){
                ll j = itr / div_2;
                if(div_2 * (j + 1) <= r){
                    m++;
                    ans.push_back({itr,div_2 * (j + 1)});
                    itr = div_2 * (j + 1);
                    break;

                }
            }
            div_2 &= ~(1ull<<i);
        }
    }
    cout<<m<<endl;
    for (int i = 0; i < m; ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
