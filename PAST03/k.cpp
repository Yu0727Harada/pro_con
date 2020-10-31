//
// Created on 2020/10/29.
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


int desk(int target,vector<int> &ans,vector<int> &link){
    if(ans[target] != 0) return ans[target];
    if(link[target]<0){
        ans[target] = abs(link[target]);
        return abs(link[target]);
    }else{
        ans[target] = desk(link[target],ans,link);
        return abs(ans[target]);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>last_item(n+1,0);
    vector<int>link(n+1,0);
    vector<int>ans(n+1,0);
    for (int i = 1; i <= n; ++i) {
        last_item[i] = i;
        link[i] = -i;
    }

    int q;
    cin>>q;
    for (int j = 0; j < q; ++j) {
        int f,t,x;
        cin>>f>>t>>x;
        int next_last_item = last_item[f];
        if(link[x] > 0){
            last_item[f] = link[x];
        }else{
            last_item[f] = 0;
        }
        if(last_item[t] == 0){
            link[x] = -t;
        }else{
            link[x] = last_item[t];
        }
        last_item[t] = next_last_item;
    }
    for (int k = 1; k <= n; ++k) {
        if(ans[k] == 0){
            desk(k,ans,link);
        }
    }
    for (int l = 1; l <= n; ++l) {
        cout<<ans[l]<<endl;
    }
    return 0;
}
