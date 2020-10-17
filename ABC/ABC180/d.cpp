//
// Created on 2020/10/17.
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
const long long LINF =1e18 + 1e9;
const int INF = 1e9;

vector<ll>beki(34,LINF);
int dis(ll last){
    beki[0] = last;//a
    for (int i = 1; i < 31; ++i) {
        if(beki[i-1] <= LINF / beki[i-1]){
            beki[i] = beki[i-1] * beki[i-1];
        }else{
           return i;
        }
    }
    return 30;
}

ll se(ll target){
    ll ret=1;
    for (int i = 0; i < 31; ++i) {
        if(target & (1<<(i))){
            ret *= beki[i];
        }
    }
    return ret;

}

int main() {

    ll x,y,a,b;
    cin>>x>>y>>a>>b;
    ll ans = 0;
    int upper = dis(a);
    if((a-1) * x < b){
        ll ok = 0;
        ll ng = 64;
        ll mid = (ok+ng)/2;
        while(abs(ok - ng) > 1){
            if((se(mid) * x) * (a-1) < b && se(mid) * x < y && se(mid)<LINF/x){
                ok = mid;
            }else{
                ng = mid;
            }
            mid = (ok+ng)/2;
        }
        ans += ok;
        x *= se(ok);
    }

    ll b_add = ((y-1)-x)/b;

    ans += b_add;


    cout<<ans<<endl;
    return 0;
}
