//
// Created on 2023/08/19.
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

vector<int> topological_sort(vector<vector<int>> &G, vector<int> &indegree, int V,set<int> uni) {
    // トポロジカルソートを記録する配列
    vector<int> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    queue<int> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        int v = que.front();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // 頂点vを配列の末尾に追加する
        sorted_vertices.push_back(v);
    }

    // トポロジカルソートを返す
    return sorted_vertices;
}



int main() {
    int n;
    cin>>n;

    vvi edge(n,vi());
    vvi b_edge(n,vi());
    vi indegree(n,0);
     for (int i = 0; i < n; ++i) {
        int c;
        cin>>c;
        for (int j = 0; j < c; ++j) {
            int p;
            cin>>p;
            p--;
            edge[p].push_back(i);
            indegree[p] += 1;
            b_edge[i].push_back(p);
        }
    }
     set<int> visited;
    vector<int> ans;
     auto dfs = [&](auto dfs, int v) -> void{
         visited.insert(v);
         for(int u: b_edge[v]){
             if(visited.count(u) == 0){
                 dfs(dfs,u);
             }
         }

     };
    dfs(dfs,0);

     vector<int> sorted_vertices = topological_sort(b_edge,indegree,n,visited);

    vi order(n);
    for (int i = 0; i < n; ++i) {
        order[sorted_vertices[i]] = i;
    }


    for (int i = 1; i < n; ++i) {
            if(visited.count(i) >= 1)ans.push_back(i);
    }
    sort(all(ans),[&](int x, int y){return order[x] > order[y];});
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i] + 1<<endl;
    }

    return 0;
}
