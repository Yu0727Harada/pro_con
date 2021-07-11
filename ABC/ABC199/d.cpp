//
// Created on 2021/04/24.
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

    int n,m;
    cin>>n>>m;

    vvi edge(n,vi());
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if(edge[i].size() >= 3){
            cout<<0<<endl;
            return 0;
        }
    }


    ll ans = 0;
    int ind = 0;
    queue<pair<vi, int>> q;
    vi color(n,-1);
    //-1は未訪問
    q.push({color,-1});

    while(!q.empty()){
        vi now_c = q.front().first;
        int now_v = q.front().second + 1;
        q.pop();

        if(now_v == n){
            continue;
        }
        if(edge[now_v].empty()){
            ind ++;
            q.push({now_c,now_v});
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            bool ok = true;
            for (int j = 0; j < edge[now_v].size(); ++j) {
                if(now_c[edge[now_v][j]] == i){
                    ok = false;
                }
            }
            if(ok){
                vi next_c = now_c;
                next_c[now_v] = i;
                if(now_v + 1 == n){
                    ans ++;
                    continue;
                }
                q.push({next_c,now_v});
            }
        }

    }

    if(ans == 0 && ind >= 1){
        ans = 1;
    }
    for (int i = 0; i < ind; ++i) {
        ans *= 3;
    }

    cout<<ans<<endl;

    return 0;
}
