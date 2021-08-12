//
// Created on 2021/08/08.
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
    vvi load(h,vi(w,0));
    vvi visit(h,vi(w,INF));
    for (int i = 0; i < h; ++i) {
        string t;
        cin>>t;
        for (int j = 0; j < w; ++j) {
            if(t[j] == '#')load[i][j] = 1;
        }
    }

    //queue<pair<pair<int,int>,int>>q;
     priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;

    q.push({0,{0,0}});

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };

    vector<vector<pair<int,int>>> pan = {
            {{0,1},{0,2},{1,1},{1,2},{-1,1},{-1,2}},
            {{1,0},{2,0},{1,1},{2,1},{1,-1},{2,-1}},
            {{-1,0},{-2,0},{-1,1},{-2,1},{-1,-1},{-2,-1}},
            {{0,-1},{0,-2},{1,-1},{1,-2},{-1,-1},{-1,-2},}
    };

    while(!q.empty()){
        pair<int,int> now_p = q.top().second;
        int cnt = q.top().first;
        q.pop();
        if(visit[now_p.first][now_p.second] < cnt){
            continue;
        }
        visit[now_p.first][now_p.second] = cnt;
        for (int i = 0; i < 4; ++i) {
            pair<int,int> next;
            next.first = now_p.first + move[i].first;
            next.second = now_p.second + move[i].second;

            if(0 <= next.first && next.first < h && 0 <= next.second && next.second < w){
                if(load[next.first][next.second] == 0 && visit[next.first][next.second] > cnt){
                    visit[next.first][next.second] = cnt;
                    q.push({cnt,next});
                }

                for (int j = 0; j < 6; ++j) {
                    pair<int,int>target;
                    target.first = now_p.first + pan[i][j].first;
                    target.second = now_p.second + pan[i][j].second;
                    if(0 <= target.first && target.first < h && 0 <= target.second && target.second < w){
                        if(visit[target.first][target.second] > cnt + 1){
                            visit[target.first][target.second] = cnt + 1;
                            q.push({cnt + 1,target});
                        }
                    }

                }


            }

        }

    }

    cout<<visit[h-1][w-1]<<endl;

    return 0;
}
