//
// Created on 2020/03/22.
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

int main() {

    int n;
    cin>>n;
    vector<int>A(n);
    map<int,long long>mp;
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
        mp[A[i]] += 1;
    }
    long long sum = 0;
    map<int,long long>mp2;
    for(auto x:mp){
        mp2[x.first] = ((x.second)*(x.second-1))/2;
        sum += mp2[x.first];
    }

    map<int,long long>mp3;
    for(auto x:mp){
        mp3[x.first] = ((mp[x.first]-1)*(mp[x.first]-2))/2;
    }

    for (int j = 0; j < n; ++j) {
        long long ans = 0;
        ans = sum - mp2[A[j]] + mp3[A[j]];
        cout<<ans<<endl;
    }

}

//long long = int + intはオーバーフローします