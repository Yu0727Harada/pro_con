//
// Created on 2021/11/05.
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

    vvi b(n,vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>b[i][j];
        }
    }
    bool ok = true;
    if(b[0][0] % 7 + m > 8)ok = false;
    if(b[0][0] % 7 == 0 && m != 1)ok =false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if(b[i+1][j] != b[i][j] + 7){
                ok = false;
            }
            if(b[i][j + 1] != b[i][j] + 1){
                ok = false;
            }
        }
        if(b[i+1][m-1] != b[i][m-1] + 7){
            ok = false;
        }
    }
    for (int j = 0; j < m-1; ++j) {
        if(b[n-1][j + 1] != b[n-1][j] + 1){
            ok = false;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
