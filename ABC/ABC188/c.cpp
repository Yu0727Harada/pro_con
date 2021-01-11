//
// Created on 2021/01/10.
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

    int n ;
    cin>>n;
    int cnt =pow(2,n);
    vector<vector<pair<int,int>>> log(18,vector<pair<int,int>>());

    for (int i = 0; i < cnt; ++i) {
        int a;
        cin>>a;
        log[0].push_back({i+1,a});
    }
    int day = 0;
    while(true){
        if(log[day].size() == 2){
            if(log[day][0].second > log[day][1].second){
                cout<<log[day][1].first<<endl;
            }else{
                cout<<log[day][0].first<<endl;
            }
            break;
        }

        for (int i = 0; i < log[day].size(); i += 2) {
            if(log[day][i].second > log[day][i+1].second){
                log[day + 1].push_back({log[day][i]});
            }else{
                log[day+1].push_back(log[day][i+1]);
            }
        }
        day++;
    }




    return 0;
}
