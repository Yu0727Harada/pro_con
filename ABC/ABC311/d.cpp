
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

vvi visit;
vvi grid;

pair<int,int> go(int muki, int now_i, int now_j){
    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };
    visit[now_i][now_j] = max(visit[now_i][now_j],1);
    while(grid[now_i + move[muki].first][now_j + move[muki].second]){
        now_i += move[muki].first;
        now_j += move[muki].second;
        visit[now_i][now_j] = max(visit[now_i][now_j],1);
    }
    return {now_i,now_j};
}

struct q_i{
public:
    int i;
    int j;
    int muki;
    q_i(int _i, int _j, int _muki){
        this->i = _i;
        this->j = _j;
        this->muki = _muki;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    grid.resize(n,vi(m,0));
    visit.resize(n,vi(m,0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < m; ++j) {
            if(s[j] == '.')grid[i][j] = 1;
        }
    }
    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };
    int now_i = 1;
    int now_j = 1;
    visit[now_i][now_j] = 2;
    queue<q_i>q;
    for (int i = 0; i < 4; ++i) {
        if(grid[now_i + move[i].first][now_j + move[i].second]){
            q_i tmp(now_i,now_j,i);
            q.push(tmp);
        }
    }
    while(!q.empty()){
        int i = q.front().i;
        int j = q.front().j;
        int muki = q.front().muki;
        q.pop();
        pair<int,int> next;
        next = go(muki,i,j);
        if(visit[next.first][next.second] != 2){
            for (int k = 0; k < 4; ++k) {
                if(grid[next.first + move[k].first][next.second + move[k].second]){
                    q_i tmp(next.first,next.second,k);
                    q.push(tmp);
                }
            }
            visit[next.first][next.second] = 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(visit[i][j])ans++;

        }
    }
    cout<<ans<<endl;

    return 0;
}
