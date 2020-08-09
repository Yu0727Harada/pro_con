//
// Created on 2020/02/13.
//

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

bool solve(){
    string a;
    string b;
    string c;
    cin>>a>>b>>c;

    for (int i = 0; i < a.size(); ++i) {
        if(a[i]==b[i] && a[i]==c[i])continue;
        else if(a[i] == b[i]) return false;
        else{
            if(a[i]==c[i] || b[i]==c[i]) continue;
            else return false;
        }
    }
    return true;


}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        if (solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}
