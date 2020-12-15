//
// Created on 2020/12/13.
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
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    if(n == m){
        cout<<0<<endl;
        return 0;
    }
    int stmp = INF;
    for (int i = 0; i < m; ++i) {
        cin>>a[i];
    }
    sort(all(a));
    int b = 1;
    for (int i = 0; i < m; ++i) {
        if(a[i] != b){
            stmp = min(stmp,a[i] - b);
        }
        b = a[i] + 1;
    }

    int ans = 0;
    int now = 1;
    for (int i = 0; i < m; ++i) {
        ans += (a[i] - now  +(stmp - 1))/stmp;
        now = a[i]+1;
    }
    if(now <= n){
        ans += (n + 1 - now + (stmp -1))/stmp;
    }
    cout<<ans<<endl;
    return 0;
}
