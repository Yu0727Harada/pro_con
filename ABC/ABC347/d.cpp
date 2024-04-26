//
// Created by yu on 2024/04/26.
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

ll bit_count(ll i){
    //数字iを二進数表記にした際の1の数を調べる
    if (i==0) return 0;
    return bit_count(i>>1ull) + (i & 1ull);
}

int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll c_cnt = bit_count(c);

    if(a > b){
        swap(a,b);
    }
    ll sub = b - a;

    ll ans_a = 0;
    ll ans_b = 0;
    for (ll i = 0; i < 60; ++i) {
        if(c & (1ull<<i)){
            if(sub > 0){
                sub--;
                b |= (1ull<<i);
            }else if(a >= b && a > 0){
                a--;
                a |= (1ull<<i);
            }else if(b > 0){
                b |= (1ull<<i);
            }else{
                if(a == 0 && b == 0){
                    cout<<ans_a<<" "<<ans_b<<endl;
                }else{
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
