//
// Created by yu on 2024/04/30.
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
    string s;
    cin>>s;
    vl cost(n);
    for (int i = 0; i < n; ++i) {
        cin>>cost[i];
    }
    vl zero_one(n,0);
    vl one_zero(n,0);
    if(s[0] == '0')one_zero[0] = cost[0];
    else if(s[0] == '1')zero_one[0] = cost[0];
    for (int i = 1; i < n; ++i) {
        if(i % 2 == 0){
            if(s[i] == '0'){
                one_zero[i] = one_zero[i - 1] + cost[i];
                zero_one[i] = zero_one[i - 1];
            }else{
                zero_one[i] = zero_one[i - 1] + cost[i];
                one_zero[i] = one_zero[i - 1];
            }
        }else{
            if(s[i] == '1'){
                one_zero[i] = one_zero[i - 1] + cost[i];
                zero_one[i] = zero_one[i - 1];
            }else{
                zero_one[i] = zero_one[i - 1] + cost[i];
                one_zero[i] = one_zero[i - 1];
            }
        }
    }
    ll ans = LINF;

    for (int i = 1; i < n; ++i) {
        chmin(ans,one_zero[i - 1] + (zero_one[n - 1] - zero_one[i - 1]));
        chmin(ans,zero_one[i-1] + (one_zero[n-1] - one_zero[i - 1]));
    }

    cout<<ans<<endl;
    return 0;
}
