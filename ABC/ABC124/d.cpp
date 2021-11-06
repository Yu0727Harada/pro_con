//
// Created on 2021/10/28.
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
    int n,k;
    cin>>n>>k;
    int ans = 0;

    string s;
    cin>>s;

    int cnt = 0;
    char last = ':';
    vector<pair<char,int>>v;
    for (int i = 0; i < s.size(); ++i) {
        if(last == s[i])cnt++;
        else{
            v.push_back({last,cnt});
            cnt = 1;
            last = s[i];
        }
    }
    v.push_back({last,cnt});
    int temp_k = 0;
    int i = 0;
    int temp_ans = 0;
    while(temp_k < k && i < v.size()){
        if(v[i].first == '0'){
            temp_k++;
            temp_ans += v[i].second;
        }else{
            temp_ans += v[i].second;
        }
        i++;
    }
    chmax(ans,temp_ans);
    int l = 1;
    for (int j = i; j < v.size() && l < v.size(); ++j) {
        if(v[j].first == '0'){
            temp_ans += v[j].second;
            if(v[l].first == '0'){
                temp_ans -=v[l].second;
                l ++;
            }else{
                temp_ans -=v[l].second;
                l++;
                if(l + 1 < v.size()){
                    temp_ans -= v[l].second;
                    l ++;
                }
            }
        }else{
            temp_ans += v[j].second;
        }
        chmax(ans,temp_ans);
    }
    cout<<ans<<endl;
    return 0;
}
