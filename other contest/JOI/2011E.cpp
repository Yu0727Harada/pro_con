//
// Created on 2020/07/09.
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
    int h,w,n;
    cin>>h>>w>>n;
    vector<vector<int>>cheese(h,vector<int>(w,INF));
    vector<pair<int,int>>c_number(n+1);
    for (int i = 0; i < h; ++i) {
        string line;
        cin>>line;
        for (int j = 0; j < w; ++j) {
            if(line[j] == 'S'){
                c_number[0] = {i,j};
            }else if(line[j] == 'X'){
                cheese[i][j] = -1;
            }else{
                c_number[line[j] - '0'] = {i,j};
            }
        }
    }

    vector<pair<int,int>>move = {{0,1},{1,0},{-1,0},{0,-1}};
    int ans_f = 0;
    for (int k = 0; k < n; ++k) {
        auto map = cheese;
        queue<vector<int>>q;
        int ans_t = 0;
        q.push({c_number[k].first,c_number[k].second,0});
        while(!q.empty()){
            int n_h = q.front()[0];
            int n_w = q.front()[1];
            int cnt = q.front()[2];
            q.pop();
            if(map[n_h][n_w] > cnt){
                map[n_h][n_w] = cnt;
            }else{
                continue;
            }
            for (int i = 0; i < move.size(); ++i) {
                int next_h = n_h + move[i].first;
                int next_w = n_w + move[i].second;
                if(0 <= next_h && next_h < h && 0 <= next_w && next_w < w && cheese[next_h][next_w] != -1){
                    q.push({next_h,next_w,cnt + 1});
                }
            }
        }
        ans_f += map[c_number[k + 1].first][c_number[k + 1].second];
    }
    cout<<ans_f<<endl;

    return 0;
}
