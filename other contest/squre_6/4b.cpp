//
// Created on 2020/06/23.
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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    //n個の要素のbit全探索する
    ll ans = LINF;
    for (int bit = 0; bit < (1<<n); ++bit) {
        int max_high = 0;
        int can_see = 0;
        ll cost = 0;
        auto a_c = a;
        for (int i = 0; i < n; ++i) {
            if(bit & (1<<i)){
                //i個目の要素にフラグが立っていた時の処理
                if(max_high >= a_c[i]){
                    cost += max_high - a_c[i] + 1;
                    a_c[i] = max_high + 1;
                }
            }
            if(max_high < a_c[i]){
                max_high = max(max_high,a_c[i]);
                can_see ++;
            }
        }
        if(can_see >= k){
            ans = min(ans,cost);
        }
    }
    cout<<ans<<endl;


    return 0;
}
