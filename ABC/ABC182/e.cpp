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


bool light[1510][1510];
bool wall[1510][1510];
bool ok[1510][1510];
vector<vector<bool>> memo(1510,vector<bool>(1510,false));
vector<vector<bool>> visited(1510,vector<bool>(1510,false));
int h,w;


bool f(int v,int j,int k){
    const vector<pair<int,int>> move = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1},
    };

    if(j < 0 || j >= h || k < 0 || k >= w) return false;
    if(light[j][k]) return true;
    if(wall[j][k]) return false;
    if(visited[j][k])return memo[j][k];
    visited[j][k] = true;
    return memo[j][k] = f(v,j+move[v].first,k+move[v].second);

}

int main() {
    int n,m;
    cin>>h>>w>>n>>m;
    for (int i = 0; i < n; ++i) {
        int r,c;
        cin>>r>>c;
        r--;
        c--;
        light[r][c] = true;
    }
    for (int i = 0; i < m; ++i) {
        int r,c;
        cin>>r>>c;
        r--;
        c--;
        wall[r][c] = true;
    }
    for (int i = 0; i < 4; ++i) {
        memo = vector<vector<bool>>(1510,vector<bool>(1510,false));
        visited = vector<vector<bool>>(1510,vector<bool>(1510,false));
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                if(f(i,j,k))ok[j][k] = true;
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(ok[i][j]) ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
