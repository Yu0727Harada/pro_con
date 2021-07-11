//
// Created on 2021/05/01.
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
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int>> c(n);
    vector<pair<int,int>> d(n);
    vector<pair<int,int>> e(n);

    vvi status(n,vi());

    for (int i = 0; i < n; ++i) {
        int A,B,C,D,E;
        cin>>A>>B>>C>>D>>E;
        status[i] = {A,B,C,D,E};
        a[i] = {A,i};
        b[i] = {B,i};
        c[i] = {C,i};
        d[i] = {D,i};
        e[i] = {E,i};
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));
    sort(all(e));


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vi maxl(5);
            int min_v = INF;
            int min_index = -1;
            for (int k = 0; k < 5; ++k) {
                maxl[k] = max(status[i][k],status[j][k]);
                if(min_v > maxl[k]){
                    min_v = maxl[k];
                    min_index = k;
                }
            }



        }
    }

    return 0;
}
