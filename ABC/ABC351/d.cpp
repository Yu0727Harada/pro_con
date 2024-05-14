//
// Created by yuha on 2024/05/13.
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

int h,w;
vvi go_g;

int bfs(int i,int j,vvi g,vi &visit){
    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };
    queue<pair<int,int>>q;
    q.push({i,j});
    visit[i * w + j] = 1;
    vvi t_visit(h,vi(w,0));
    t_visit[i][j] = 1;
    int cnt = 0;
    while(!q.empty()){
        int n_i = q.front().first;
        int n_j = q.front().second;
        q.pop();
        cnt++;
        bool go = true;
        if(go_g[n_i][n_j] == -1){
            for (int k = 0; k <4; ++k) {
                if(0 <= n_i + move[k].first && n_i + move[k].first < h && 0 <= n_j + move[k].second && n_j + move[k].second < w){
                    if(!g[(n_i + move[k].first)][n_j + move[k].second]){
                        go = false;
                    }
                }
            }
        }else if(go_g[n_i][n_j] == 0){
            go = false;
        }else{
            go = true;
        }
        if(!go)visit[n_i * w + n_j] = 0;

        for (int k = 0; k <4; ++k) {
            if(0 <= n_i + move[k].first && n_i + move[k].first < h && 0 <= n_j + move[k].second && n_j + move[k].second < w){
                int v_posi = (n_i + move[k].first) * w + n_j + move[k].second;
                if(t_visit[n_i + move[k].first][n_j + move[k].second])continue;
                if(visit[v_posi])continue;
                if(!g[(n_i + move[k].first)][n_j + move[k].second])continue;

                if(go){
                    visit[v_posi] = 1;
                    t_visit[n_i + move[k].first][n_j + move[k].second] = 1;
                    //u.unite(v_posi,n_i * w + n_j);
                    q.push({n_i + move[k].first,n_j + move[k].second});
                }
            }
        }

    }
    return cnt;
};

int main() {

    cin>>h>>w;
    vvi g(h,vi(w,1));
    go_g.resize(h,vi(w,-1));
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#')g[i][j] = 0;
        }
    }

    vi visit(h * w,0);
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(visit[i * w + j])continue;
            bool go = true;
            vector<pair<int,int>> move = {
                        {0,  1},
                        {1,  0},
                        {-1, 0},
                        {0,  -1},
                };
            if(go_g[i][j] == -1) {
                for (int k = 0; k < 4; ++k) {
                    if (0 <= i + move[k].first && i + move[k].first < h && 0 <= j + move[k].second &&
                        j + move[k].second < w) {
                        if (!g[(i + move[k].first)][j + move[k].second]) {
                            go = false;
                        }
                    }
                }
            }else if(go_g[i][j] == 0){
                go = false;
            }else{
                go = true;
            }
            if(!go){
                chmax(ans,1);
                continue;
            }
            if(g[i][j])chmax(ans,bfs(i,j,g,visit));
        }
    }

    cout<<ans<<endl;

    return 0;
}
