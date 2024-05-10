//
// Created by yu on 2023/12/23.
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
    ll a;
    cin>>a;
    ll m;
    cin>>m;
    ll l;
    ll r;
    cin>>l>>r;
    ll cnt = 0;
    if(a <= l){
        cnt += (r - a) / m + 1;
        cnt -= (l - a) / m + 1;
        if((l - a) % m == 0)cnt++;
        //lに木が生えてたら

    }else if(l < a && a < r){
        cnt += (a - l ) / m + 1;
        cnt += (r - a ) / m + 1;
        cnt--;
    }else{
        cnt += (a - l) / m + 1;
        cnt -= (a - r) / m + 1;
        if((r - a) % m == 0)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
