//
// Created on 2020/11/01.
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

    map<int,int>mp;
    mp[0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]-'0'] ++;
    }
    if(s.size()<=1){
        if(s[0]=='8'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    if(s.size()<=2){
        for (int i = 16; i <= 99; i += 8) {
            map<int,int>use;
            string target = to_string(i);
            use[target[0]-'0']++;
            use[target[1]-'0'] ++;
            bool ok = true;
            for (int j = 0; j <= 10; ++j) {
                if(mp[j] >= use[j]){
                    continue;
                }else{
                    ok = false;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }else{
        for (int i = 104; i <= 999; i+=8) {
            map<int,int>use;
            string target = to_string(i);
            use[target[0]-'0']++;
            use[target[1]-'0'] ++;
            use[target[2]-'0']++;
            bool ok = true;
            for (int j = 0; j <= 10; ++j) {
                //cout<<mp[j]<<use[j]<<endl;
                if(mp[j] >= use[j]){
                    continue;
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
