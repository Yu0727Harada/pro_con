//
// Created by 原田 on 2022/06/13.
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


// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<int> topological_sort(vector<vector<int>> &G, vector<int> &indegree, int V) {
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

int main(void) {
    // 頂点数と辺の本数
    int n, m;
    cin>>n>>m;

    // 隣接リストにより表現されるグラフ
    vector<vector<int>> G(n);

    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    // 頂点の入次数を記録する配列
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        indegree[v] += 1;
    }

    // トポロジカルソートする
    vector<int> sorted_vertices = topological_sort(G, indegree, n);


    vl check(n,LINF);

    ll f_ans = -LINF;
    for (int i = 0; i < sorted_vertices.size(); ++i) {

        ll ans = -LINF;
        ll sale = a[sorted_vertices[i]];
        check[sorted_vertices[i]] = sale;
        queue<pair<int,int>>q;
        for (int j = 0; j < G[sorted_vertices[i]].size(); ++j) {
            if(check[G[sorted_vertices[i]][j]] == LINF){
                q.push({G[sorted_vertices[i]][j],sale});
            }
        }
        while(!q.empty()){
            int p = q.front().first;
            int sale_t = q.front().second;
            q.pop();

            chmax(ans,a[p] - sale_t);
            if(check[p] < sale_t)continue;
            check[p] = sale_t;
            if(sale < a[p])sale_t = a[p];
            for (int j = 0; j < G[p].size(); ++j) {
                if(check[G[p][j]] > sale_t){
                q.push({G[p][j],sale_t});

                }
            }

        }
        chmax(f_ans,ans);


    }


    return 0;
}