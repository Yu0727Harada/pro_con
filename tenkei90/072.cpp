//
// Created by 原田 on 2022/05/11.
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

int ans = 0;

void walk(int x,int y,int cnt,int s_x,int s_y,vvi grid){
    vector<pair<int,int>> move = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1},
    };
    grid[x][y] = cnt;

    for (int i = 0; i < 4; ++i) {
        if(x + move[i].first == s_x && y + move[i].second == s_y){//start
            chmax(ans,cnt);
        }else if(grid[x + move[i].first][y + move[i].second] == 0){
            walk(x + move[i].first,y + move[i].second,cnt + 1,s_x,s_y,grid);
        }
    }
}

int main() {
    int h,w;


    cin>>h>>w;

    vvi grid(h + 2,vi(w + 2,-1));
    for (int i = 1; i <= h; ++i) {
        string s;
        cin>>s;
        for (int j = 1; j <= w; ++j) {
            if(s[j - 1] == '#'){
                grid[i][j] = -1;
            }else{
                grid[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(grid[i][j] == -1)continue;
            walk(i,j,1,i,j,grid);
        }
    }
    if(ans <= 3)ans = -1;
    cout<<ans<<endl;

    return 0;
}
//DFS　バックトラック
//ABC 王国は H 行 W 列のマス目で表されます。各マスは山のマスと平野のマスのどちらかです。上から i 行目、左から j 列目にあるマスが山のマスなら c[i][j] は '#'、平野のマスなら c[i][j] は '.' です。
//
//あなたは鉄道路線をすべて作りたいです。鉄道路線の経路は、以下の条件をすべて満たす必要があります。
//[条件 1]　あるマスを始点とし、辺を共有して隣接するマスに移動することを k 回 (3 ≦ k) 繰り返し、始点で終わる経路である。
//[条件 2]　 k 回の移動について、移動先は相異なる。（始点と終点は一致してよい）
//[条件 3]　山のマスを通らない。
//
//この鉄道路線が通るマスの数の最大値を求めてください。条件を満たす鉄道路線がない場合は、代わりにそれを報告してください。
//
//【制約】
//・H,W は正整数
//・HW ≦ 16
//・c[i][j] は '#' または '.' である
//・c[i][j] が '.' である i, j (1 ≦ i ≦ H, 1 ≦ j ≦ W) が 1 つ以上存在する