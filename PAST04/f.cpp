//
// Created on 2020/11/08.
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
    int n,k;
    cin>>n>>k;

    map<string,int>mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        mp[s]++;
    }
    vector<vector<string>>dict(n+3,vector<string>());
    for(auto item:mp){
        dict[item.second].push_back(item.first);
    }

    int cnt = 0;
    for (int i = n ; i >= 0; --i) {
        if(!dict[i].empty()){
            cnt += dict[i].size();
        }
        if(cnt == k){
            if(dict[i].size() == 1){
                cout<<dict[i][0]<<endl;
            }else{
                cout<<"AMBIGUOUS"<<endl;
            }
            return 0;
        }
    }


    cout<<"AMBIGUOUS"<<endl;



    return 0;
}
