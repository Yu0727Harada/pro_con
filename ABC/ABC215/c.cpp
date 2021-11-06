//
// Created on 2021/08/21.
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
    vector<char> li(s.size());
    for (int i = 0; i < s.size(); ++i) {
        li[i] = s[i];
    }

    vector<int> v(s.size());
    iota(v.begin(), v.end(), 0);       // v に 1, 2, ... N を設定

    map<string,int>mp;

    do {
        string temp;
        for (int i = 0; i < v.size(); ++i) {
            temp += li[v[i]];
        }

        mp[temp] ++;
        //cout << x << " "; cout << "\n";    // v の要素を表示
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    int k;
    cin>>k;
    int cnt = 1;
    for(auto item:mp){
        if(k == cnt){
            cout<<item.first<<endl;
            return 0;
        }
        cnt ++;

    }

    return 0;
}
