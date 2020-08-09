//
// Created on 2020/04/05.
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
    int ans;
    vector<vector <int> > tumiki (3);
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int n = a1+a2+a3;
    vector<int>v(n);
    iota(v.begin(),v.end(),1);

    tumiki[0] = vector<int>(a1);
    tumiki[1] = vector<int>(a2);
    tumiki[2] = vector<int>(a3);
    int cnt = 0;
    do{
        bool ok = true;
        for (int i = 0; i < a1; ++i) {
            tumiki[0][i] = v[i];
        }
        for (int j = 0; j < a2; ++j) {
            tumiki[1][j] = v[a1+j];
        }
        for (int k = 0; k < a3; ++k) {
            tumiki[2][k] = v[a1+a2+k];
        }
        for (int l = 0; l < a1 -1; ++l) {
            if(tumiki[0][l] > tumiki[0][l+1]){
                ok = false;
            };
        }
        for (int m = 0; m < a2 -1; ++m) {
            if(tumiki[1][m] > tumiki[1][m+1]){
                ok = false;
            }
        }
        for (int m = 0; m < a2 ; ++m) {
            if(tumiki[0][m] > tumiki[1][m]){
                ok = false;
            }
        }

        for (int i1 = 0; i1 < a3 -1; ++i1) {
            if(tumiki[2][i1] > tumiki[2][i1 +1]){
                ok = false;
            }

        }
        for (int i1 = 0; i1 < a3; ++i1) {
            if(tumiki[1][i1] > tumiki[2][i1]){
                ok = false;
            }
        }

        if(ok)cnt++;
    }while(next_permutation(v.begin(),v.end() ));





    cout<<cnt<<endl;
}
