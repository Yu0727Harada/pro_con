//
// Created on 2021/03/27.
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
    int x,y;
    cin>>y>>x;
    x--;
    y--;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin>>g[i];
    }

    int ans = 0;
    int n_x;
    int n_y;

    if(g[y][x] == '.'){
        ans++;
    }else{
        cout<<ans<<endl;
        return 0;
    }


    n_x = x - 1;
    n_y = y;
    while(n_x >= 0){
        if(g[n_y][n_x] == '.'){
            ans ++;
        }else{
            break;
        }
        n_x --;
    }

    n_x = x + 1;
    n_y = y;
    while(n_x < w){
        if(g[n_y][n_x] =='.'){
            ans++;
        }else{
            break;
        }
        n_x ++;
    }


    n_y = y - 1;
    n_x = x;
    while(n_y >= 0){
        if(g[n_y][n_x] == '.'){
            ans ++;
        }else{
            break;
        }
        n_y --;
    }

    n_y = y + 1;
    n_x = x;
    while(n_y < h){
        if(g[n_y][n_x] =='.'){
            ans++;
        }else{
            break;
        }
        n_y ++;
    }
    cout<<ans<<endl;


    return 0;
}
