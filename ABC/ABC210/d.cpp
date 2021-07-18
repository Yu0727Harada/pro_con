//
// Created on 2021/07/17.
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
    int h,w;
    cin>>h>>w;
    ll c;
    cin>>c;

    ll min_v = LINF;
    pair<int,int> min_index = {-1,-1};
    vector<vector<ll>> a(h,vl(w,0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin>>a[i][j];
            if(a[i][j] < min_v){
                min_v = a[i][j];
                min_index = {i,j};
            }
        }
    }
    ll cost = LINF;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ll dis = abs(min_index.first - i)+abs(min_index.second - j);
            if(dis == 0)continue;
            ll temp_cost = dis * c;
            temp_cost += a[i][j] + min_v;
            chmin(cost,temp_cost);
        }
    }

    cout<<cost<<endl;
    return 0;

}
