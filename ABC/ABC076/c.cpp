//
// Created on 2020/12/08.
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
    string t;
    cin>>t;
    vector<string>ans_l;
    for (int i = 0; i < s.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < t.size(); ++j) {
            if(s[i + j] == t[j] || s[i + j] == '?'){
                if(i + j + 1 > s.size()){
                    ok = false;
                    break;
                }
                continue;
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            string ans = s;
            for (int j = 0; j < t.size(); ++j) {
                ans[i + j] = t[j];
            }
            for (int j = 0; j < ans.size(); ++j) {
                if(ans[j] == '?'){
                    ans[j] = 'a';
                }
            }
            ans_l.push_back(ans);
        }
    }
    if(ans_l.size() == 0){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }else{
        sort(all(ans_l));
        cout<<ans_l[0]<<endl;
        return 0;
    }
}
