//
// Created on 2023/07/05.
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

vvi g(2100,vi(2100,0));


void bfs(int& ret, int x, int y){
    vector<pair<int,int>> m = {{-1,-1},
                               {-1,0},
                               {0,-1},
                               {0,+1},
                               {+1,0},
                               {+1,+1}};
    ret++;
    g[x][y] = 2;
    for (int i = 0; i < m.size(); ++i) {
        int next_x = x + m[i].first;
        int next_y = y + m[i].second;
        if(g[next_x][next_y] == 1){
            bfs(ret, next_x, next_y);
        }
    }

}


int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> l(n);

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        x += 1010;
        y += 1010;
        g[x][y] = 1;
        l[i] = {x,y};
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(g[l[i].first][l[i].second] == 1){
            int r = 0;
            bfs(r, l[i].first, l[i].second);
            ans++;
        }

    }
    cout<<ans<<endl;


    return 0;
}
