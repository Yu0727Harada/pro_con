//
// Created by 原田 on 2021/07/19.
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
    int h,w;
    cin>>h>>w;
    vector<vector<int>> g(h,vector<int>(w,0));
    UnionFind u(h * w);
    int q;
    cin>>q;
    while(q){
        q--;
        int t;
        cin>>t;
        if(t == 1){
            int r,c;
            cin>>r>>c;
            r--;c--;
            g[r][c] = 1;
            int num = (r) * w + c;
            vector<pair<int,int>> move = {
                        {0,  1},
                        {1,  0},
                        {-1, 0},
                        {0,  -1},
            };
            for (int i = 0; i < 4; ++i) {
                int next_r = r + move[i].first;
                int next_c = c + move[i].second;
                if(0 <= next_r && next_r < h && 0 <= next_c && next_c < w){
                    if(g[next_r][next_c] == 1){
                        int next_num = (next_r) * w + next_c;
                        u.unite(num,next_num);
                    }
                }
            }
        }else{
            int ra,ca,rb,cb;
            cin>>ra>>ca>>rb>>cb;
            ra--;ca--;rb--;cb--;
            if(g[ra][ca] == 1 && g[rb][cb] == 1){
                int num_a = (ra ) * w + ca;
                int num_b = (rb ) * w + cb;
                if(u.same(num_a,num_b)){
                    cout<<"Yes"<<endl;
                    continue;
                }
            }
            cout<<"No"<<endl;
        }
    }

    return 0;
}
