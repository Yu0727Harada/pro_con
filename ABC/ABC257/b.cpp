//
// Created on 2022/06/25.
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
    int n,k;
    int q;
    cin>>n>>k>>q;
    vi mass(n + 1,0);
    for (int i = 0; i < k; ++i) {
        int l;
        cin>>l;
        mass[l] = 1;
    }
    for (int i = 0; i < q; ++i) {
        int l;
        cin>>l;
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if(mass[j] == 1)cnt++;
            if(cnt == l){
                if(j == n)continue;
                if(mass[j +1] == 1)continue;
                swap(mass[j + 1],mass[j]);
            }
        }
    }
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
        if(mass[j] == 1){
            cnt++;
            if(cnt != k) cout<<j<<" ";
            else cout<<j<<endl;
        }

    }
    return 0;
}
