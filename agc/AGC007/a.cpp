
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
    queue<vector<int>>q;
    vector<vector<bool>>grid(h+2,vector<bool>(w+2,false));
    vector<vector<int>>int_grid(h+2,vector<int>(w+2,INF));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            char t;
            cin>>t;
            if(t == '#'){
                grid[i][j] = true;
            }
        }
    }

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
//                {-1, 0},
//                {0,  -1},
        };
    q.push({1,1,0});
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        chmin(int_grid[x][y],cnt);
        for (int i = 0; i < 2; ++i) {
            int next_x = x + move[i].first;
            int next_y = y + move[i].second;
            if(grid[next_x][next_y]){
                q.push({next_x,next_y,cnt+1});
            }
        }
    }

    if(int_grid[h][w] == INF){
        cout<<"Impossible"<<endl;
        return 0;
    }

    map<int,int>mp;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(int_grid[i][j] == INF && grid[i][j]){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if(int_grid[i][j] == INF)continue;
            mp[int_grid[i][j]] ++;
            if(mp[int_grid[i][j]] > 1){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }

    cout<<"Possible"<<endl;
    return 0;
}
