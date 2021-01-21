//
// Created on 2021/01/18.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;

    vl a(n);
    vl b(n);
    vl a_max_l(n);
    cin>>a[0];
    a_max_l[0] = a[0];
    for (int i = 1; i < n; ++i) {
        cin>>a[i];
        a_max_l[i] = max(a_max_l[i-1],a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }

    ll a_max = 0;
    ll b_max = 0;
    int b_index = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {

        b_max = b[i];
        b_index = i;


        if(ans < b_max * a_max_l[b_index]){
            ans = b_max * a_max_l[b_index];
        }
        cout<<ans<<endl;
    }

    return 0;
}
