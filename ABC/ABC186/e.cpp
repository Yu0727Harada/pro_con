//
// Created on 2020/12/19.
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
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int n;
        int s;
        int k;
        cin>>n>>s>>k;
        int move = n % k;
        if((n - s) / move == 0){
            cout<<n/move<<endl;
            continue;
        }else{
            int mod = n % move;
            if(n - mod + move == s){
                cout<<-1<<endl;
            }
            int loop_move = s - (n - mod + move);
            int  ans = (mod / loop_move) * n/move;

            cout<<ans<<endl;
        }

    }
    return 0;
}
