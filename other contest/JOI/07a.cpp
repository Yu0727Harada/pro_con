//
// Created on 2020/06/11.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int m;
    cin>>m;
    vector<pair<int,int>>star(m-1);
    int x_standard,y_standard;
    cin>>x_standard>>y_standard;
    for (int i = 0; i < m - 1; ++i) {
        int x,y;
        cin>>x>>y;
        star[i] = {x - x_standard,y - y_standard};
    }
    int n;
    cin>>n;
    vector<pair<int,int>>stars(n);
    map<pair<int,int>,bool>sky;
    for (int j = 0; j < n; ++j) {
        int x,y;
        cin>>x>>y;
        sky[{x,y}] = true;
        stars[j] = {x,y};
    }

    for (int k = 0; k < n; ++k) {
        int x,y;
        x = stars[k].first;
        y = stars[k].second;
        bool ok = true;
        for (int i = 0; i < m-1; ++i) {
            int x_m = x + star[i].first;
            int y_m = y + star[i].second;
            if(x_m >= 0 && y_m >= 0){
               if(!(sky[{x_m,y_m}])){
                   ok = false;
                   break;
               }
            }
        }
        if(ok){
            printf("%d %d\n",x - x_standard,y - y_standard);
        }
    }
    return 0;
}

//mapで座標を持っておくbool型で