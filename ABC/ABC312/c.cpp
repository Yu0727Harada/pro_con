//
// Created on 2023/07/29.
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

    int n,m;
    cin>>n>>m;

    vector<int>sale(n);
    vector<int>buy(m);
    for (int i = 0; i < n; ++i) {
        cin>>sale[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>buy[i];
    }

    sort(all(sale));
    sort(all(buy));

    int ok = INF + 10;
    int ng = 0;
    int mid;
    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;

        auto sale_it = upper_bound(all(sale), mid);w
        size_t sale_pos;
        if(sale_it == sale.end())sale_pos = n;
        else sale_pos = distance(sale.begin(), sale_it) ;


        auto buy_it = upper_bound(all(buy),mid - 1);
        size_t buy_pos;

        if(buy_it == buy.end()) buy_pos = m;
        else buy_pos = distance(buy.begin(),buy_it) ;

        if(sale_pos >= m - buy_pos )ok = mid;
        else ng = mid;

    }
    cout<<ok<<endl;

    return 0;
}
