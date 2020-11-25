//
// Created on 2020/11/25.
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
    int n ,k;
    cin>>n>>k;
    vector<int>x_m;
    vector<int>x_p;
    x_p.push_back(0);
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        if(t >= 0){
            x_p.push_back(t);
        }else{
            x_m.push_back(t);
        }
    }
    int fi_ans = INF;
    for (int i = 0; i < x_m.size(); ++i) {
        int ans = abs(x_m[i]);
        if(x_m.size() - i > k) continue;
        if(k-(x_m.size()-i) >= x_p.size()){
            continue;
        }
        ans += x_p[k-(x_m.size()-i)];
        ans += min(x_p[k-(x_m.size()-i)],abs(x_m[i]));
        chmin(fi_ans,ans);
    }
    if(x_p.size() >=k+1){
        int ans = x_p[k];
        chmin(fi_ans,ans);
    }
    cout<<fi_ans<<endl;
    return 0;
}
