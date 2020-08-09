//
// Created on 2020/07/08.
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
    int r,c;
    cin>>r>>c;
    int start_y,start_x;
    cin>>start_y>>start_x;
    start_y--;
    start_x--;
    int goal_y,goal_x;
    cin>>goal_y>>goal_x;
    vector<vector<int>>grid(r,vector<int>(c,INF));
    //0=>. -1=?#
    for (int i = 0; i < r; ++i) {
        string line;
        cin>>line;
        for (int j = 0; j < c; ++j) {
            if(line[j] == '#'){
                grid[i][j] = -1;
            }
        }
    }
    queue<vector<int>>q;
    vector<pair<int,int>>move = {{1,0},{0,1},{-1,0},{0,-1}};
    q.push({start_x,start_y,0});
    while(!q.empty()){
        int x,y,cnt;
        x = q.front()[0];
        y = q.front()[1];
        cnt = q.front()[2];
        q.pop();
        if(grid[y][x] > cnt){
            grid[y][x] = cnt;
        }else{
            continue;
        }
        for (int i = 0; i < move.size(); ++i) {
            int m_x = move[i].first;
            int m_y = move[i].second;
            int next_x = x + m_x;
            int next_y = y + m_y;
            if(1 <= next_x && next_x < c - 1 && 1<= next_y && next_y < r - 1 && grid[next_y][next_x] > cnt + 1){
                q.push({next_x,next_y,cnt+1});
            }
        }
    }
    cout<<grid[goal_y-1][goal_x-1]<<endl;
    return 0;
}
