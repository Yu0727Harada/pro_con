//
// Created on 2020/12/03.
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
    int r,c,d;
    cin>>r>>c>>d;
    int max_v_even = 0;
    int max_v_odd = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j =1; j <= c; ++j) {
            int t;
            cin>>t;
            if(i + j - 2 <= d){
                if((i + j)% 2 == 0){
                    chmax(max_v_even,t);
                } else{
                    chmax(max_v_odd,t);
                }
            }
        }
    }
    if(d % 2 == 0){
        cout<<max_v_even<<endl;
    }else{
        cout<<max_v_odd<<endl;
    }
    return 0;
}
