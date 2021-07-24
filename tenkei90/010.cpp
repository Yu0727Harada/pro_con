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



int main() {
    int n;
    cin>>n;
    vl one(n + 1,0);
    vl two(n + 1,0);

    for (int i = 1; i <= n; ++i) {
        int c;
        ll p;
        cin>>c>>p;
        if(c == 1){
            one[i] += p;
        }else{
            two[i] += p;
        }
        one[i] += one[i-1];
        two[i] += two[i-1];
    }
    int q;
    cin>>q;
    while(q){
        q--;
        int l,r;
        cin>>l>>r;
        ll a;
        ll b;
        a = one[r] - one[l-1];
        b = two[r] - two[l-1];
        cout<<a<<" "<<b<<endl;
    }

    return 0;
}
