//
// Created on 2020/10/01.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>E_line(n+1,0);
    vector<int>W_line(n+1,0);
    for (int i = 1; i <= n; ++i) {
        if(s[i-1]== 'E'){
            E_line[i]++;
        }else{
            W_line[i]++;
        }
        E_line[i] += E_line[i-1];
        W_line[i] += W_line[i-1];
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int number = E_line[n] - E_line[i];
        number += W_line[i - 1];
        chmin(ans,number);
    }
    cout<<ans<<endl;
    return 0;
}
