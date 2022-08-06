//
// Created by 原田 on 2022/03/29.
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

    ll x;
    cin>>x;

    vl v;
    v.push_back(0);
    for (int i = 1; i <= 9; ++i) {//最初に始める数字
        v.push_back(i);
        for (int j = 0; j <= 9; ++j) {//差がいくつか
            ll now = i;
            ll last = i;
            for(int k = 0; k < 17;k++) {
                now *= 10;
                int next = last + j;
                if (next > 9)break;
                now += next;
                last = next;
                v.push_back(now);
            }
        }
    }
    for (int i = 1; i <= 9; ++i) {//最初に始める数字
        for (int j = 1; j <= 9; ++j) {//差がいくつか
            ll now = i;
            ll last = i;
            for(int k = 0; k < 17;k++){
                 now *= 10;
                int next = last - j;
                if(next < 0)break;
                now += next;
                last = next;
                v.push_back(now);
            }
        }
    }

    sort(all(v));

    int ok = v.size();
    int ng = 0;
    int mid;
    while(ok - ng > 1){
        mid = (ok + ng) / 2;
        if(x > v[mid]){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout<<v[ok]<<endl;


    return 0;
}
