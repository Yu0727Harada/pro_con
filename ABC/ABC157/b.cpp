//
// Created on 2020/03/01.
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

int main() {
    bool ans = false;
    vector<vector <int> > bingo (3,vector<int>(3,0));
    for (int i = 0; i < 3; ++i) {
        cin>>bingo[i][0]>>bingo[i][1]>>bingo[i][2];
    }
    int n;
    cin>>n;
    for (int j = 0; j < n; ++j) {
        int temp;
        cin>>temp;
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k < 3; ++k) {
                if(temp==bingo[i][k]){
                    bingo[i][k]=0;
                }
            }
        }
    }

    for (int l = 0; l < 3; ++l) {
        if(bingo[l][0]==0 && bingo[l][1] == 0 &&  bingo[l][2] == 0) ans = true;
    }
    for (int l = 0; l < 3; ++l) {
        if (bingo[0][l] ==0 && bingo[1][l]==0 &&  bingo[2][l] == 0) ans = true;
    }
    if(bingo[0][0] == 0 && bingo[1][1] ==0 && bingo[2][2]==0) ans =true;
    if(bingo[0][2] == 0 && bingo[2][0] ==0&& bingo[1][1]==0) ans = true;

    if (ans){
        cout<<"Yes"<<endl;
        return 0;
    }
        cout<<"No"<<endl;
}
