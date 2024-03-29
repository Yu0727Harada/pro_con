//
// Created by 原田 on 2022/01/28.
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
    int n,k;
    cin>>n>>k;
    vector<int>v(n + 1 ,0);
    vector<int>p(n);
    for (int i = 0; i < n; ++i) {
         cin>>p[i];
    }
    vector<int>ans(n);
    ans[n - 1] = n - k + 1;
    int now = n - k + 1;
    for (int i = n - 1; i >= k; --i) {
        if(p[i] >= now){
            now --;
            v[p[i]] = 1;
            while(v[now] != 0){
                now --;
            }
            ans[i - 1] = now;
        }else{
            v[p[i]] = 1;
            ans[i - 1] = now;
        }
    }
    for (int i = k-1; i < n; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
