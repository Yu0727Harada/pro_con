//
// Created on 2022/06/18.
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

    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].first>>v[i].second;
    }

    sort(all(v));

    int n_l = -1;
    int n_r = -1;
    vector<pair<int,int>>ans;
    for (int i = 0; i < n; ++i) {
        int lt, rt;
        lt = v[i].first;
        rt = v[i].second;
        if(n_l == -1){
            n_l = lt;
            n_r = rt;
        }else{
            if(lt > n_r){
                ans.push_back({n_l,n_r});
                n_l = lt;
                n_r = rt;
                continue;
            }
            if(rt <= n_r){
                continue;
            }else if(rt > n_r){
                n_r = rt;
            }
        }
    }
    ans.push_back({n_l,n_r});
    sort(all(ans));
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}
