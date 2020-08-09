//
// Created on 2020/07/12.
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
    int h,w;
    cin>>h>>w;

    int ok = 0;

    vector<vector<int>>grid(h + 2,vector<int>(w + 2,-1));
    for (int i = 1; i <= h; ++i) {
        string line;
        cin>>line;
        for (int j = 1; j <= w; ++j) {
            if(line[j-1] == '.'){
                grid[i][j] = INF;
                ok ++;
            }else{
                grid[i][j] = -1;
            }
        }
    }
    queue<vector<int>>q;
    vector<pair<int,int>>move = {{1,0},{0,1},{-1,0},{0,-1}};
    q.push({1,1,1});
    //h,w,cnt
    while(!q.empty()){
        int now_h = q.front()[0];
        int now_w = q.front()[1];
        int cnt = q.front()[2];
        if(grid[now_h][now_w] > cnt){
            grid[now_h][now_w] = cnt;
            for (int i = 0; i < move.size(); ++i) {
                int next_h = now_h + move[i].first;
                int next_w = now_w + move[i].second;
                if(grid[next_h][next_w] > cnt){
                    q.push({next_h,next_w,cnt + 1});
                }
            }
        }
        q.pop();
    }
    int ans;
    if(grid[h][w] == INF){
        ans = -1;
    }else{
        ans = ok - grid[h][w];
    }
    cout<<ans<<endl;
    return 0;
}
