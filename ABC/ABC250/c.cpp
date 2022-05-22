//
// Created on 2022/05/08.
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

    int n,q;
    cin>>n>>q;

    vector<int> v(n + 1);//i-status v=value
    iota(v.begin(), v.end(), 0);

    vector<int> r_v(n + 1);//i-value v=status
    iota(r_v.begin(), r_v.end(), 0);

    for (int i = 0; i < q; ++i) {
        int x;
        cin>>x;
        if(r_v[x] == n){
            int target = v[n - 1];
            r_v[target] = n;
            r_v[x] = n - 1;
            v[n - 1] = x;
            v[n] = target;
        }else{
            int x_status = r_v[x];
            int target_v = v[x_status + 1];
            r_v[target_v] = x_status;
            r_v[x] = x_status + 1;
            v[x_status] = target_v;
            v[x_status + 1] = x;
        }
    }
   for ( int i = 1; i < v.size(); i++ )
   {
   	cout << v[i] << ( i + 1 < v.size() ? ' ' : '\n' );
   }
   cout << flush;

    return 0;
}
