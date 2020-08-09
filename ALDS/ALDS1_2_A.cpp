//
// Created on 2020/01/16.
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
//typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
//using gragh = vector<vector<int>>;

void bubbleSort(vector<int> &A,int N,int &c){
    bool frag = true;
    while (frag){
        frag = false;
        for (int i = N-1; i >= 1 ; --i) {
            if (A[i] <A[i-1]){
                swap(A[i],A[i-1]);
                c ++;
                frag = true;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>A(n);
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    int count = 0;
    bubbleSort(A,n,count);
    for (int j = 0; j < n; ++j) {
        if(j==0) cout<<A[j];
        else cout<<" "<<A[j];
    }
    cout<<endl;
    cout<<count<<endl;

}

