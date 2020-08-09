//
// Created on 2020/06/27.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    int m;
    ll k;
    cin>>n;
    cin>>m;
    cin>>k;
    vector<ll>a(n+2,LINF);
    vector<ll>b(m+2,LINF);

    ll a_sum = 0;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll temp;
        cin>>temp;
        a_sum += temp;
        a[i] = a_sum;
    }
    ll b_sum = 0;
    b[0] = 0;
    for (int j = 1; j <= m; ++j) {
        ll temp;
        cin>>temp;
        b_sum += temp;
        b[j] = b_sum;
    }
    ll ans = 0;
    for (int l = 0; l <= n; ++l) {
        ll time = k - a[l];
        if(time < 0){
            break;
        }
        ll ok = 0;
        ll ng = m+1;
        ll mid = (ok + ng)/2;
        while(abs(ok - ng) != 1){
            if(b[mid] > time){
                ng = mid;
                mid = (ok+ng)/2;
            }else{
                ok = mid;
                mid = (ok+ng)/2;
            }
        }
        ans = max((l) + (ok),ans);
    }
    cout<<ans<<endl;

    return 0;
}
