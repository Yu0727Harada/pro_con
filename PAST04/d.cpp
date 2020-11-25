//
// Created on 2020/11/08.
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
    int left_side = 0;
    int right_side = 0;
    int max_cnt = 0;

    int i;
    for (i = 0; i < n; ++i) {
        if(s[i] == '.'){
            left_side ++;
        }else{
            break;
        }
    }
    int j;
    for (j = n-1; j >= 0; --j) {
        if(s[j] == '.'){
            right_side ++;
        }else{
            break;
        }
    }

    int cnt = 0;
    for (int k = i+1; k < j; ++k) {
        if(s[k] == '.'){
            cnt ++;
        }else{
            chmax(max_cnt,cnt);
            cnt = 0;
        }
    }
    chmax(max_cnt,cnt);
    cnt = 0;
    int ans_x = left_side;
    int ans_y = right_side;
    ans_x += max(max_cnt - (left_side + right_side),0);

    cout<<ans_x<<" "<<ans_y<<endl;

    return 0;
}
