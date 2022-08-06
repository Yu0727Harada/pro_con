//
// Created on 2022/07/09.
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
    string s;
    string t;
    cin>>s>>t;

    vector<pair<char,int>> s2;
    vector<pair<char,int>> t2;

    char now = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i - 1] == s[i]){
            cnt++;
        }else{
            s2.push_back({now,cnt});
            cnt = 1;
            now = s[i];
        }
    }
    s2.push_back({now,cnt});

    now = t[0];
    cnt = 1;
    for (int i = 1; i < t.size(); ++i) {
        if(t[i - 1] == t[i]){
            cnt++;
        }        else{
            t2.push_back({now,cnt});
            cnt = 1;
            now = t[i];
        }
    }
    t2.push_back({now,cnt});
    bool ok = true;
    if(t2.size() == s2.size()){
        for (int i = 0; i < s2.size(); ++i) {
            if(s2[i].first == t2[i].first && s2[i].second == t2[i].second){
                continue;
            }else if(s2[i].first == t2[i].first && s2[i].second >= 2 && s2[i].second < t2[i].second){
                continue;
            }
            else{
                ok = false;
            }
        }
    }else{
        ok = false;
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
