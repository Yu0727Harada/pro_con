//
// Created on 2020/11/30.
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
    string s;
    cin>>s;

    int a_cnt = 0;
    int b_cnt = 0;
    int c_cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'a'){
            a_cnt ++;
        }else if(s[i] == 'b'){
            b_cnt ++;
        }else{
            c_cnt ++;
        }
    }

    int min_cnt = min(a_cnt,min(b_cnt,c_cnt));
    a_cnt -= min_cnt;
    b_cnt -= min_cnt;
    c_cnt -= min_cnt;
    if(a_cnt >= 2){
        cout<<"NO"<<endl;
    }else if(b_cnt >= 2){
        cout<<"NO"<<endl;
    }else if(c_cnt >= 2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}
