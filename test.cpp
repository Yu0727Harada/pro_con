
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




vector<vector<pair<int,int>>> edge;


void walk(int now, int cnt, vi log, vector<bool> visit,int &t_ans){
    visit[now] = true;
    for (int i = 0; i < edge[now].size(); ++i) {
        int next = edge[now][i].first;
        int next_cost = edge[now][i].second;

        if(log[next] <= cnt + next_cost && !visit[next]){
            log[next] = cnt + next_cost;
            chmax(t_ans,cnt + next_cost);
            walk(next, cnt + next_cost, log,visit,t_ans);
        }
    }

}

int main() {
    int n,m;
    cin>>n>>m;

    edge.resize(n);


    for (int i = 0; i < m; ++i) {
        int a;
        int b;
        int c;
        cin>>a>>b>>c;
        a--;
        b--;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> visit(n);
        visit[i] = true;
        vi log(n,0);
        int t_ans = 0;
        walk(i,0,log,visit,t_ans);


        chmax(ans,t_ans);
    }

    cout<<ans<<endl;
    return 0;
}
