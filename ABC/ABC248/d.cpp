//
// Created by 原田 on 2022/04/19.
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
    vvi a(n+1,vi(1,0));
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin>>tmp;
        a[tmp].push_back(i+1);
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        int l,r,x;
        cin>>l>>r>>x;
        int l_cnt,r_cnt;

        int ok,ng,mid;
        ok = 0;
        ng = a[x].size();

        while(abs(ng - ok) > 1){
            mid = (ok + ng)/2;
            if(l <= a[x][mid]){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        l_cnt = ok;
        ok = 0;
        ng = a[x].size();

        while(abs(ng - ok) > 1){
            mid = (ok + ng)/2;
            if(r >= a[x][mid]){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        r_cnt = ok;
        cout<<r_cnt - l_cnt<<endl;

    }
    return 0;
}
