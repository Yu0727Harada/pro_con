//
// Created on 2020/12/04.
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
const long long LINF =1e18;
const int INF = 1e9;
vector<int>ng(10000,0);


struct UnionFind {
    vector<int>d;//リンクの情報,子の場合は親の番号、親の場合は連結成分のsize*(-1)
    UnionFind(int n=0):d(n,-1){} //structの初期化。デフォルトのnを0に設定してdを-1(すなわち全ての成分は親であり、サイズは1にする
    int find(int x) {//根を探す
        if(d[x] < 0 ) return x;
        else  return d[x] = find(d[x]);//根じゃなかったら根を探しに行ってメモ化する。
    }
    bool unite(int tx,int ty) {//成分を連結する
        int x = find(tx);
        int y = find(ty);
        if (x == y) {
            ng[tx] = 1;
            ng[ty] = 1;
            ng[x] = 1;
            ng[y] = 1;
            //閉路があったらそのノードをマークする
            return false;//すでに同じ連結成分
        }
        if(d[x] < d[y]) swap(x,y);//大きいのに小さいのをつける。x←y
        //x.size > y.size
        d[x] += d[y];//xのサイズをふやす
        d[y] = x;//yの根をxにする
        return true;
    }
    bool same(int x,int y) {return find(x)==find(y);}
    int size(int x) {return -d[find(x)];}
};

int main() {
    int n,m;
    cin>>n>>m;

    UnionFind s(n);

    for (int i = 0; i < m; ++i) {
        int v,u;
        cin>>v>>u;
        u--;
        v--;
        if(!s.unite(v,u)){

        }
    }
    for (int i = 0; i < n; ++i) {
        if(ng[i]){
            ng[s.find(i)] = 1;
            //マークしたノードの根もマークする
        }
    }


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(s.d[i] < 0 && ng[i] == 0){
            //マークしてなくて根なら数える
            ans ++;
        }
    }

    cout<<ans<<endl;
    return 0;
}

//UnionFindで閉路検出　グラフの数を数える