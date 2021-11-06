<<<<<<< HEAD
//
// Created by 原田 on 2021/10/26.
//

=======
>>>>>>> origin/master

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
<<<<<<< HEAD
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<pair<int,int>>box(n);
    for (int i = 0; i < n; ++i) {
        cin>>box[i].first>>box[i].second;
    }

    vector<vector<vector<int>>> dp(n + 1,vvi(x + 1,vi(y + 1,INF)));
    dp[0][0][0] = 0;//何も買わないので０で達成できる

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x + 1; ++j) {
            for (int k = 0; k < y + 1; ++k) {
                int tako = box[i].first;
                int tai = box[i].second;
                if(dp[i + 1][min(x,j + tako)][min(y,k + tai)] > dp[i][j][k] + 1){
                    dp[i + 1][min(x,j + tako)][min(y,k + tai)] = dp[i][j][k] + 1;
                }
                if(dp[i + 1][j][k] > dp[i][j][k]){
                    dp[i + 1][j][k] = dp[i][j][k];
                }
            }
        }
    }

    if(dp[n][x][y] == INF){
        cout<<-1<<endl;
    }else {

        cout << dp[n][x][y] << endl;
    }
    return 0;
}
//
//D - Strange Lunchbox
//N 種類の弁当が、それぞれ 1 個ずつ売られています。
//i=1,2,…,N について、i 種類目の弁当には Ai​ 個のたこ焼きと Bi​ 個のたい焼きが入っています。
//
//高橋君は、 X 個以上のたこ焼きと Y 個以上のたい焼きを食べたいです。
//高橋君がいくつかの弁当を選んで買うことで、 X 個以上のたこ焼きと Y 個以上のたい焼きを手に入れることが可能かどうか判定して下さい。また、可能な場合はそのために高橋君が購入しなければならない弁当の個数の最小値を求めて下さい。
//
//各種類の弁当は 1 個しか売られていないため、同じ種類の弁当を 2 個以上購入することは出来ないことに注意して下さい。
=======

    int n;
    cin>>n;

    return 0;
}
>>>>>>> origin/master
