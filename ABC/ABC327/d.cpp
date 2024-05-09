//
// Created by yu on 2023/11/13.
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
    int n,m;
    cin>>n>>m;
    vi a(m);
    vi b(m);
    vvi edge(n,vi());

    bool ok = true;
    for (int i = 0; i < m; ++i) {
        cin>>a[i];
        a[i]--;
    }
    for (int i = 0; i < m; ++i) {
        cin>>b[i];
        b[i]--;
    }

    for (int i = 0; i < m; ++i) {
        if(a[i] == b[i]) ok = false;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }

    vi l(n,-1);
    queue<pair<int,int>>q;
    for (int i = 0; i < edge.size(); ++i) {
        if (edge[i].size() > 0 && l[i] == -1) {
            q.push({i, 0});
        }

        while (!q.empty()) {
            int v = q.front().first;
            int c = q.front().second;
            q.pop();
            if (l[v] == -1)l[v] = c;
            else if (l[v] != c) {
                ok = false;
                break;
            } else {
                continue;
            }
            for (int i = 0; i < edge[v].size(); ++i) {
                if (l[edge[v][i]] == -1) {
                    q.push({edge[v][i], (c + 1) % 2});
                } else if (l[edge[v][i]] != (c + 1) % 2) {
                    ok = false;
                    break;
                }
            }
        }
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
