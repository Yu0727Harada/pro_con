//
// Created on 2021/08/29.
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
    int m;
    cin>>n>>m;

    vvi edge;
    vector<set<int>> re_edge;
    edge.resize(n,vi());
    re_edge.resize(n,set<int>());

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        re_edge[b].insert(a);
    }

     priority_queue<int, vector<int>, greater<int>>p_que;

    for (int i = 0; i < n; ++i) {
        if(re_edge[i].empty()){
            p_que.push(i);
        }
    }
    vi visit(n,0);
    vi ans;
    while(!p_que.empty()){
        int v = p_que.top();
        p_que.pop();

        ans.push_back(v+1);
        for (int i = 0; i < edge[v].size(); ++i) {
            re_edge[edge[v][i]].erase(v);
            if(visit[edge[v][i]] == 0 ){
                if(re_edge[edge[v][i]].empty()){
                    p_que.push(edge[v][i]);
                    visit[edge[v][i]] = 1;
                }
            }
        }
    }

    if(ans.size() == n){
        for ( int i = 0; i < ans.size(); i++ )
        {
        	cout << ans[i] << ( i + 1 < ans.size() ? ' ' : '\n' );
        }
        cout << flush;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}
