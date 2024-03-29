//
// Created by 原田 on 2022/07/04.
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
    int k;
    cin>>k;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    vvi dp(n,vi(2,-1));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 0; i < n - 1; ++i) {
        if(abs(a[i + 1] - a[i]) <= k && dp[i][0] == 1){
            dp[i + 1][0] = 1;
        }
        if(abs(a[i + 1] - b[i]) <= k && dp[i][1] == 1){
            dp[i + 1][0] = 1;
        }
        if(abs(b[i + 1] - a[i]) <= k && dp[i][0] == 1){
            dp[i + 1][1] = 1;
        }
        if(abs(b[i + 1] - b[i]) <= k && dp[i][1] == 1){
            dp[i + 1][1] = 1;
        }
    }

    if(dp[n - 1][0] == 1 || dp[n-1][1] == 1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
