//
// Created on 2020/11/25.
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
    string t;
    cin>>s>>t;


    vector<vector<int>>s_list(26,vector<int>());
    vector<vector<int>>t_list(26,vector<int>());

    for (int i = 0; i < s.size(); ++i) {
        int s_index = s[i] -'a';
        int t_index = t[i] -'a';
        s_list[s_index].push_back(i);
        t_list[t_index].push_back(i);
    }

    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != t[i]){
            int t_index = t[i] - 'a';
            if(t_list[t_index].size() == 1)continue;
            else{

            }
        }

    }

    return 0;
}
