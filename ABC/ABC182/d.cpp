//
// Created on 2020/11/08.
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

    int n;
    cin>>n;

    vector<ll>max_plus(n+1,0);
    vector<ll>sum(n+1,0);
    ll start = 0;
    ll end = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin>>a;
        sum[i] = sum[i-1] + a;
        end = start + sum[i];
        ll max_point = max_plus[i-1] + start;
        if(max_point > end){
            max_plus[i] = max_plus[i-1];

        }else{
            max_plus[i] = end - start;
        }
        chmax(ans,start+max_plus[i]);
        start = end;
    }
    cout<<ans<<endl;
    return 0;
}
