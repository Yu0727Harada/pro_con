//
// Created on 2020/11/08.
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
    int h,w;
    cin>>h>>w;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>block_h(h,vector<int>());
    vector<vector<int>>block_w(w,vector<int>());
    vector<pair<int,int>>akari;

    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        akari.push_back({a,b});
    }
    for (int j = 0; j < m; ++j) {
        int c,d;
        cin>>c>>d;
        c--;
        d--;
        block_h[c].push_back(d);
        block_w[d].push_back(c);
    }

    for (int l = 0; l < h; ++l) {
        sort(all(block_h[l]));
    }
    for (int l = 0; l < w; ++l) {
        sort(all(block_w[l]));
    }

    int ans = 0;
    for (int k = 0; k < n; ++k) {
        int a_h = akari[k].first;
        int a_w = akari[k].second;


        int ok = h;
        int ng = 0;
        int mid = (ok+ng)/2;

        if(block_h[a_h].size() != 0){

            while(abs(ok-ng) > 1){
                if(block_h[a_h][ok] > a_w){
                    ok = mid;
                }else{
                    ng = mid;
                }
                mid = (ok+ng)/2;
            }
            ans += abs(block_h[a_h][ok] -block_h[a_h][ng]);
        }else{
            ans += h;
        }
        ok = w;
        ng = 0;
        mid = (ok+ng)/2;

        if(block_w[a_w].size() != 0){

            while(abs(ok-ng) > 1){
                if(block_w[a_w][ok] > a_w){
                    ok = mid;
                }else{
                    ng = mid;
                }
                mid = (ok+ng)/2;
            }
            ans += abs(block_h[a_w][ok] -block_h[a_w][ng]);
        }else{
            ans += w;
        }
        ans --;
    }

    cout<<ans<<endl;
    return 0;
}
