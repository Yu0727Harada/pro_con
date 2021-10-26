//
// Created by 原田 on 2021/10/22.
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



int main() {
    int h,w;
    cin>>h>>w;

    vvi g(h,vi(w,INF));

    int rs,cs;
    cin>>rs>>cs;
    int rt,ct;
    cin>>rt>>ct;
    rs--;
    cs--;
    rt--;
    ct--;

    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#'){
                g[i][j] = -1;
            }
        }
    }

    queue<pair<pair<int,int>,int>>q;
    q.push({{rs,cs},0});


    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(g[r][c] < cnt)continue;

        for (int i = 0; i < 4; ++i) {
            int n_r = r;
            int n_c = c;
            int n_cnt = cnt + 1;
            while(true){
                n_r = n_r + move[i].first;
                n_c = n_c + move[i].second;
                if(0 <= n_r && n_r < h && 0 <= n_c && n_c < w){
                   if(g[n_r][n_c] >= n_cnt){
                       q.push({{n_r,n_c},n_cnt});
                       g[n_r][n_c] = n_cnt;
                   }else{
                       break;
                   }
               }else{
                   break;
               }
            }
        }
    }

    cout<<g[rt][ct] - 1<<endl;

    return 0;
}
