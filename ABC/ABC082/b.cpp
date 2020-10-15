//
// Created on 2020/10/13.
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

    sort(all(s));
    sort(rall(t));

    if(s[0] < t[0]){
        cout<<"Yes"<<endl;
        return 0;
    }else if(s[0] == t[0]){
        if(s.size() < t.size()){
            bool ok = false;
            bool same = true;
            for (int i = 0; i < min(s.size(),t.size()); ++i) {
                if(s[i] < t[i]) {
                ok = true;
                }
                if(s[i] != t[i]){
                    same = false;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
            if(same && s.size()<t.size()){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;


    return 0;
}
