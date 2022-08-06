//
// Created by 原田 on 2022/03/21.
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
    vector<char>s(3);
    vector<char>t(3);

    map<vector<char>,int>mp_1;
    map<vector<char>,int>mp_2;
    vector<pair<int,int>>swap_a = {{0,1},{0,2},{1,2}};

    for (int i = 0; i < 3; ++i) {
        cin>>s[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin>>t[i];
    }
    queue<pair<vector<char>,int>>q;
    q.push({s,0});
    while(!q.empty()){
        vector<char>s_tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < swap_a.size(); ++i) {
            auto t_tmp = s_tmp;
            swap(t_tmp[swap_a[i].first],t_tmp[swap_a[i].second]);
            if((cnt + 1) % 2 == 0){
                if(mp_2[t_tmp] == 0){
                    mp_2[t_tmp]++;
                    q.push({t_tmp,cnt + 1});
                }
            }else{
                if(mp_1[t_tmp] == 0){
                    mp_1[t_tmp]++;
                    q.push({t_tmp,cnt + 1});
                }
            }
        }
    }
    if(mp_2[t] == 0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}
