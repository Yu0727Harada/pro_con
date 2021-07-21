//
// Created by 原田 on 2021/07/20.
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

struct UnionFind {
    vector<ll>d;//リンクの情報,子の場合は親の番号、親の場合は連結成分のsize*(-1)
    UnionFind(ll n=0):d(n,-1){} //structの初期化。デフォルトのnを0に設定してdを-1(すなわち全ての成分は親であり、サイズは1にする
    int find(ll x) {//根を探す
        if(d[x] < 0) return x;
        else  return d[x] = find(d[x]);//根じゃなかったら根を探しに行ってメモ化する。
    }
    bool unite(int x,int y) {//成分を連結する
        x = find(x);
        y = find(y);
        if (x == y) return false;//すでに同じ連結成分
        if(d[x] < d[y]) swap(x,y);//大きいのに小さいのをつける。x←y
        //x.size > y.size
        d[x] += d[y];//xのサイズをふやす
        d[y] = x;//yの根をxにする
        return true;
    }
    bool same(int x,int y) {return find(x)==find(y);}
    ll size(int x) {return -d[find(x)];}

};

void dfs(int v,vector<bool> &visit,vvi &edge,priority_queue<pair<int,int>>&pq,int &cnt){
    //int v = st.top();

    //st.pop();
    visit[v] = true;
    for (int j = 0; j < edge[v].size(); ++j) {
        if(!visit[edge[v][j]]){
            int next_v = edge[v][j];
            dfs(next_v,visit,edge,pq,cnt);
        }
    }
    pq.push({cnt,v});
    cnt ++;
}

int main() {
    int n,m;
    cin>>n>>m;

    ll ans = 0;
    vvi edge(n,vector<int>());
    vvi edge_back(n,vector<int>());
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge_back[b].push_back(a);
    }

    priority_queue<pair<int,int>>pq;
    vector<bool> visit(n,false);
    stack<int>st;//u,cnt
    int cnt = 1;

    for (int i = 0; i < n; ++i) {
        if(!visit[i]){
            dfs(i,visit,edge,pq,cnt);
        }

    }

    UnionFind u(n);

    while (!pq.empty()) {
        int i = pq.top().second;
        pq.pop();
        if(visit[i]){
            st.push(i);
        }
        while(!st.empty()){
            int v = st.top();
            st.pop();
            visit[v] = false;
            for (int j = 0; j < edge_back[v].size(); ++j) {
                if(visit[edge_back[v][j]]){
                    int next_v = edge_back[v][j];
                    st.push(next_v);
                    u.unite(v,next_v);
                }
            }

        }
    }

    for (int i = 0; i < n; ++i) {
        if(u.d[i] < 0){
            ans += (u.size(i) * (u.size(i) - 1))/2;
        }
    }

    cout<<ans<<endl;
    return 0;
}
