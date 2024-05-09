//
// Created by yu on 2023/11/21.
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
    int n;
    cin>>n;;
    int m;
    cin>>m;
    vector<deque<char>>q(n+5);
    string s;
    cin>>s;
    vi c_l(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin>>c;
        c_l[i] = c;
        q[c].push_back(s[i]);
    }
    for (int i = 0; i < n+5; ++i) {
        if(!q[i].empty()){
            char tmp = q[i].back();
            q[i].pop_back();
            q[i].push_front(tmp);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<q[c_l[i]].front();
        q[c_l[i]].pop_front();
    }
    cout<<endl;
    return 0;
}
