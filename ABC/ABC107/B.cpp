//
// Created on 2020/09/24.
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

    vector<vector<bool>>grid_1(h,vector<bool>(w,false));
    vector<vector<bool>>grid_2(w,vector<bool>(h,false));
    set<int>skip_h;
    set<int>skip_w;

    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        int skip = 0;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#'){
                grid_1[i][j] = true;
                grid_2[j][i] = true;
                skip++;
            }
        }
        if(skip == 0){
            skip_h.insert(i);
        }
    }

    for (int i = 0; i < w; ++i) {
        auto sum = accumulate(all(grid_2[i]),0);
        if(sum == 0){
            skip_w.insert(i);
        }
    }

    for (int i = 0; i < h; ++i) {
        if(skip_h.count(i) >= 1) continue;
        for (int j = 0; j < w; ++j) {
            if(skip_w.count(j) >= 1) continue;
            if(grid_1[i][j] == 1){
                cout<<'#';
            }else{
                cout<<'.';
            }

        }
        cout<<endl;
    }

    return 0;
}
