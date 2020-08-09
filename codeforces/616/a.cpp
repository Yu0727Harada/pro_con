
//
// Created on 2020/02/02.
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
#include <stdio.h>


#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

void solve(){

    int d;
    cin>>d;
    string s;
    cin>>s;

    vector<int>st(d);

    transform(s.begin(), s.end(), st.begin(), [](char ch) { return ch - '0';});

    if (d==1){
        cout<<-1<<endl;
        return;
    }else if(d==2){

        if (st[0]%2==1 && st[1]%2==1){
            cout<<s<<endl;
            return;
        }else{
            cout<<-1<<endl;
            return;
        }
    }
    int end_del =1;
    int b;
    b =st[d-end_del]%2;
    while (b ==0) {
        end_del ++;
        if(end_del >d) {
            cout<<-1<<endl;
            return;
        }
        b = st[d-end_del]%2;
    }
    int stt_del = 0;
    int a;
    a = st[stt_del]%2;
    while(a == 0){
        stt_del ++;
        if(stt_del>=d) {
            cout<<-1<<endl;
            return;
        }
        a = st[stt_del]%2;
    }
    if(end_del+stt_del == d){
        cout<<-1<<endl;
        return;
    }
    cout<<s[stt_del]<<s[d-end_del]<<endl;
    return;

}

int main() {
    int n;
    cin>>n;
    while (n){
        solve();
        n--;
    }

}
