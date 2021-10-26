//
// Created by 原田 on 2021/10/15.
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
    ll n;
    cin>>n;

    vl a(n);
    vl b(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));


    double e_x;
    double e_y;
    if(n % 2 == 0){
        e_x = ((double)a[n/2-1] + (double)a[n/2])/2;
        e_y = ((double)b[n/2-1] + (double)b[n/2])/2;
    }else{
        e_x = a[n/2];
        e_y = b[n/2];
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(e_x - a[i]);
        ans += abs(e_y - b[i]);
    }
    cout<<(ll)ans<<endl;

}

//xとyを独立に考える。ソートして中央値をとる

//二次元平面上に N 棟の工場があり、i 番目の工場は座標 (X[i], Y[i]) にあります。
//
//これからあなたは二次元平面上の好きな場所を 1 つ選び、発電所を建設します。
//発電所の不便さを、発電所から各工場までのマンハッタン距離の総和と定義するとき、不便さとしてありうる最小の値を求めてください。
//
//【制約】
//・1 ≦ N ≦ 10^5
//・-10^9 ≦ X[i], Y[i] ≦ 10^9
