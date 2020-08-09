//
// Created on 2020/06/06.
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
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>>grid(600 ,vector<int>(600 ,INF));
    // -1block -2 goal(300,300)=>(0,0)
    for (int i = 0; i < n; ++i) {
        int b_x,b_y;
        cin>>b_x>>b_y;
        grid[300 + b_x][300 + b_y] = -1;
    }
    vector<pair<int,int>>move ={
            {+1,+1},
            {0,+1},
            {-1,+1},
            {+1,0},
            {-1,0},
            {0,-1}
    };

    queue<vector<int>>q;//{x,y,cnt}
    q.push({300,300,0});
    grid[300][300] = 0;
    while(!q.empty()){
        int n_x = q.front()[0];
        int n_y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        cnt ++;
        for (int i = 0; i < move.size(); ++i) {
            int m_x = n_x + move[i].first;
            int m_y = n_y + move[i].second;
            if(0 <= m_x && m_x < 600 && 0 <= m_y && m_y < 600){
                if(grid[m_x][m_y] > cnt){
                    q.push({m_x,m_y,cnt});
                    grid[m_x][m_y] = min(cnt,grid[m_x][m_y]);
                }
            }
        }
    }
    if(grid[300 + x][300 + y] == INF){
        cout<<-1<<endl;
    }else{
        cout<<grid[300 + x][300 + y]<<endl;
    }

    return 0;
}
