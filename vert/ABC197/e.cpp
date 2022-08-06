//
// Created by 原田 on 2022/06/20.
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
    cin>>n;

    vl xl(n + 1,LINF + 10);
    vl xr(n + 1,-LINF - 10);
    xl[0] = 0;
    xr[0] = 0;
    ll maxv = 0;
    for (int i = 0; i < n; ++i) {
        ll x,c;
        cin>>x>>c;
        chmin(xl[c],x);
        chmax(xr[c],x);
        chmax(maxv,c);
    }
    vl dpl(n + 5,LINF + 10);
    vl dpr(n + 5,LINF + 10);
    dpl[0] = 0;
    dpr[0] = 0;

    //l -> next_r -> next_l
    //r -> next_l -> next_r
    //l -> next_l -> next_r
    //r -> next_r -> next_l
    // 3 2 1 2 3
    int last = 0;
    for (int i = 0; i < maxv; ++i) {
        if(xl[i + 1] == LINF + 10){
            dpl[i + 1] = dpl[i];
            dpr[i + 1] = dpr[i];
        }else {

            chmin(dpl[i + 1], dpl[i] + abs(xr[i + 1] - xl[last]) + abs(xl[i + 1] - xr[i + 1]));
            chmin(dpr[i + 1], dpr[i] + abs(xl[i + 1] - xr[last]) + abs(xr[i + 1] - xl[i + 1]));
            chmin(dpr[i + 1], dpl[i] + abs(xl[i + 1] - xl[last]) + abs(xr[i + 1] - xl[i + 1]));
            chmin(dpl[i + 1], dpr[i] + abs(xr[i + 1] - xr[last]) + abs(xl[i + 1] - xr[i + 1]));
            last = i + 1;
        }
    }
    cout<<min(dpl[maxv] + abs(xl[maxv]),dpr[maxv] + abs(xr[maxv]))<<endl;


    return 0;
}
