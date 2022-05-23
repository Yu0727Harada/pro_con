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
    int n,a,b;
    cin>>n>>a>>b;
    int w_cnt = 0;
    bool w = true;
    int h_cnt = 0;
    bool h = true;
    for (int i = 0; i < a * n; ++i) {
        if(h)w = true;
        else w = false;
        for (int j = 0; j < b * n; ++j) {
            if(w)cout<<'.';
            else cout<<'#';
            w_cnt++;
            if(w_cnt == b){
                w = !w;
                w_cnt = 0;
            }
        }
        cout<<endl;
        h_cnt++;
        if(h_cnt == a){
            h = !h;
            h_cnt = 0;
        }
    }

    return 0;
}
