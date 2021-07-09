//
// Created by 原田 on 2021/06/10.
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
    string s;
    int t;
    cin>>s>>t;

    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'L'){
            x --;
        }else if(s[i] == 'R'){
            x ++;
        }else if(s[i] == 'U'){
            y ++;
        }else if(s[i] == 'D'){
            y --;
        }else{
            z ++;
        }
    }

    int ans;
    if(t == 1){
        ans = abs(x) + abs(y) + z;
    }else{
        ans = abs(x) + abs(y) - z;
        if(ans < 0){
            if(s.size() % 2 == 0){
                ans = 0;
            }else{
                ans = 1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
