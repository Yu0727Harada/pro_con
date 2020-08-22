//
// Created on 2020/08/22.
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
    int c_h,c_w;
    cin>>c_h>>c_w;
    int d_h,d_w;
    cin>>d_h>>d_w;

    vector<vector<int>>grid(h+4,vector<int>(w+4,-1));
    for (int i = 2; i <= h+1; ++i) {
        string s = "##";
        string maze;
        cin>>maze;
        maze = s + maze;
        for (int j = 2; j <= w+1; ++j) {
            if(maze[j] == '.')grid[i][j] = INF;
        }
    }

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
                };

    queue<vector<int>>q;
    queue<vector<int>>magic_q;
    q.push({c_h+1,c_w+1,0});
    grid[c_h+1][c_w+1] = 0;
    while(true){
        while(!q.empty()){
            int now_h = q.front()[0];
            int now_w = q.front()[1];
            int now_cnt = q.front()[2];
            q.pop();
            int move_cnt = 0;
            for (int i = 0; i < 4; ++i) {
                int next_h = now_h + move[i].first;
                int next_w = now_w + move[i].second;
                int next_cnt = now_cnt;
                if(grid[next_h][next_w] > next_cnt){
                    move_cnt++;
                    grid[next_h][next_w] = next_cnt;
                    q.push({next_h,next_w,next_cnt});
                }
            }
            if(move_cnt < 4){
                magic_q.push({now_h,now_w,now_cnt});
            }
        }
        int move_cnt = 0;
        while(!magic_q.empty()){
            int now_h = magic_q.front()[0];
            int now_w = magic_q.front()[1];
            int now_cnt = magic_q.front()[2];
            magic_q.pop();
            for (int i = -2; i <= 2; ++i) {
                for (int j = -2; j <= 2; ++j) {
                    int next_h = now_h + i;
                    int next_w = now_w + j;
                    int next_cnt = now_cnt + 1;
                    if(grid[next_h][next_w] > next_cnt){
                        move_cnt ++;
                        grid[next_h][next_w] = next_cnt;
                        q.push({next_h,next_w,next_cnt});
                    }
                }
            }
        }
        if(move_cnt == 0)break;
    }

    if(grid[d_h+1][d_w+1] == INF){
        cout<<-1<<endl;
    }else{

        cout<<grid[d_h+1][d_w+1]<<endl;
    }

    return 0;
}
