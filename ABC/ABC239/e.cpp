//
// Created on 2022/02/12.
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

    int n;
    cin>>n;

    int q;
    cin>>q;
    vvi max_v(n,vi());
    vi x(n);
    for (int i = 0; i < n; ++i) {
        cin>>x[i];
        max_v[i].push_back(x[i]);
    }

    vvi v(n,vi());

    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> terminal_visit(n,0);
    queue<int>que;
    stack<int>que_1;
    que.push(0);
    vi visit(n,0);

    while(!que.empty()){
        int u = que.front();
        que.pop();

        if(visit[u] == 1)continue;
        visit[u] = 1;
        que_1.push(u);

        for (int i = 0; i < v[u].size(); ++i) {
            if(visit[v[u][i]] == 0){

                que.push(v[u][i]);
            }
        }
//        if(ok){
//            terminal_visit[u] = 1;
//
//        }
    }

    while(!que_1.empty()){
        int u = que_1.top();
        que_1.pop();
        if(terminal_visit[u] == 1)continue;
        vi tmp = max_v[u];
        for (int i = 0; i < v[u].size(); ++i) {
            if(terminal_visit[v[u][i]] == 1){
                for (int j = 0; j < max_v[v[u][i]].size(); ++j) {
                    tmp.push_back(max_v[v[u][i]][j]);
                }
            }
        }
        terminal_visit[u] = 1;

        sort(rall(tmp));
        if(tmp.size() > 20)tmp.resize(20);
        max_v[u] = tmp;
    }


    for (int i = 0; i < q; ++i) {
        int l,p;
        cin>>l>>p;
        l--;
        p--;
        cout<<max_v[l][p]<<endl;
    }


    return 0;
}
