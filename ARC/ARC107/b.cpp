//
// Created on 2020/10/31.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    for (ll i = 2; i <= (2 * n); ++i) {
        ll ab_side;
        ll cd_side;
        if(i - 1 >= n- abs(i - 1 - n)){
            ab_side = n - abs(i - 1 - n);
        }else{
            ab_side = i - 1;
        }

        if(i-k-1 >= n- abs(i - k - 1 - n)){
            cd_side = n - abs(i - k - 1 - n);
        }else{
            cd_side = i-k-1;
        }
        if(cd_side > 0 && ab_side > 0){
            ans += ab_side * cd_side;
        }
    }

    cout<<ans<<endl;
    return 0;
}
