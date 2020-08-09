//
// Created on 2020/01/14.
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

void insertion_sort(vector<int>A,int N){
    for (int i = 0; i < N; ++i) {
        int temp = A[i];
        int j = i-1;
        while (j >= 0 && A[j]>temp){
            A[j+1] = A[j];
            j --;
        }
        A[j+1] = temp;
        for (int k = 0; k < N; ++k) {
            if(k!=0) cout<<" ";
            cout<<A[k];
        }
        cout<<endl;
    }
}

int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }
    insertion_sort(A,N);

}
