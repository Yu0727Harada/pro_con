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
    cin>>s;
    int k;
    cin>>k;
    map<string,int>mp;



    for (int i = 0; i < s.size(); ++i) {
        string tmp = "";
        tmp += s[i];
        mp[tmp]++;
        int cnt = 0;
        for (int j = i+1; j < s.size() && cnt <= k; ++j) {
            tmp += s[j];
            mp[tmp]++;
            cnt++;
        }
    }
    int i = 1;
    for(auto item : mp){
        if(i == k){
            cout<<item.first<<endl;
        }
        i++;
    }


    return 0;
}
//文字列の出力するものが5以下までなので5以上の長さの文字列は絶対に6番目以降に来るので調べる必要はない