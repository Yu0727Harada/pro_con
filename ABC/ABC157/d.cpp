//
// Created on 2020/03/01.
//
//#include <bits/stdc++.h>
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

struct UnionFind {
    vector<int>d;//リンクの情報,子の場合は親の番号、親の場合は連結成分のsize*(-1)
    UnionFind(int n=0):d(n,-1){} //structの初期化。デフォルトのnを0に設定してdを-1(すなわち全ての成分は親であり、サイズは1にする
    int find(int x) {//根を探す
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
    int size(int x) {return -d[find(x)];}

};



int main() {
    int n,m,k;
    cin>>n>>m>>k;
    UnionFind uf(n);
    vector<int>friend_list(n,0);//友達関係は数のみを持てばよい。友達関係であれば必ず同じ連結成分なので。

    for (int i = 0; i < m; ++i) {
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        uf.unite(A,B);//AとBを連結する
        friend_list[A]++;
        friend_list[B]++;
    }
    vector<vector<int>>block(n,vector<int>());//隣接リストを持つ
    for (int i = 0; i < k; ++i) {
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        block[A].push_back(B);
        block[B].push_back(A);
    }
    for (int j = 0; j < n; ++j) {
        int ans = uf.size(j)-1-friend_list[j];//連結成分のサイズ-自分自身-直接の友達の数
        for (int i = 0; i < block[j].size(); ++i) {//ブロック関係で回す
            if(uf.same(j,block[j][i])) ans--;//もしもブロックした人が同じ連結成分にいたらディクリメント
        }
        cout<<ans<<' ';
    }

    cout<<endl;
}

