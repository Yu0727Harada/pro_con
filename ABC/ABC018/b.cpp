//
// Created by 原田 on 2021/07/12.
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
    cin>>s;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int l,r;
        cin>>l>>r;
        l--;r--;
        string t = s;
        t = t.substr(l,r-(l-1));
        reverse(t.begin(),t.end());
        if(l == 0 && r == s.size()-1){
            s = t;
        }else if(l == 0){
            s = t + s.substr(r + 1,(s.size()-1) - r);
        }else if(r == s.size()-1){
            s = s.substr(0,l)+ t;
        }else{
            s = s.substr(0,l)+t+s.substr(r + 1,s.size()-1);
        }
    }

    cout<<s<<endl;
    return 0;
}
