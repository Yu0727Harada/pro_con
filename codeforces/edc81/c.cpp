//#include <bits/stdc++.h>
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

void solve(){
    string s;
    string t;
    cin>>s>>t;
    vector<vector <int> > g (s.size()+10,vector<int>(26,INF));
    for (int i = s.size()-1 ; i >=0 ; --i) {
        for (int j = 0; j < 26; ++j) {
            g[i][j] = g[i+1][j];
        }
        g[i][s[i]-'a'] = i;
    }

    int position = 0;
    int ans = 1;
    for (int k = 0; k < t.size(); ++k) {
        if(position == s.size()){
            position =0;
            ans ++;
        }
        if (g[position][t[k]-'a'] == INF){
            position = 0;
            ans ++;
        }
        if (g[position][t[k]-'a'] == INF && position == 0){
            ans = -1;
            break;
        }
        position = g[position][t[k]-'a'] +1;
    }
    cout<<ans<<endl;

}


int main() {
    int n;
    cin>>n;
    while(n){
        solve();
        n--;
    }


}
