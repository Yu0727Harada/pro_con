//
// Created on 2020/03/10.
//ALDS 70P stable sort



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

using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

void bubbleSort(vector<pair<int,char>> &A,int N){
    bool frag = true;
    while (frag){
        frag = false;
        for (int i = N-1; i >= 1 ; --i) {
            if (A[i].first <A[i-1].first){
                swap(A[i],A[i-1]);

                frag = true;
            }
        }
    }
}

void selection_sort(vector<pair<int,char>> &A,int N){
    for (int i = 0; i < N; ++i) {
        int min;
        min = i;
        for (int j = i; j < N; ++j) {
            if(A[j].first<A[min].first) min = j;
        }
        if (i != min){
            swap(A[i],A[min]);
        }
    }
}
int main() {

    int n;
    cin>>n;
    vector<pair<int,char>>card;
    vector<queue<char>>per(10);
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        char mark;
        int value;
        mark = s[0];
        value = s[1]-'0';
        card.push_back({value,mark});
        per[value].push(mark);
    }
    auto data = card;
    auto per_data = per;
    bubbleSort(data,n);
    bool stable = true;
    for (int j = 0; j < n; ++j) {
        if(j == n-1 ) {
            cout<<data[j].second<<data[j].first<<endl;
            continue;
        }
        cout<<data[j].second<<data[j].first<<" ";

        if(data[j].first == data[j+1].first){
            char now_mark = per_data[data[j].first].front();
            per_data[data[j].first].pop();
            if(now_mark != data[j].second) stable = false;

        }
    }
    if (stable) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;

    data = card;
    per_data = per;
    selection_sort(data,n);
    stable = true;
    for (int j = 0; j < n; ++j) {
        if(j == n-1 ) {
            cout<<data[j].second<<data[j].first<<endl;
            continue;
        }
        cout<<data[j].second<<data[j].first<<" ";

        if(data[j].first == data[j+1].first){
            char now_mark = per_data[data[j].first].front();
            per_data[data[j].first].pop();
            if(now_mark != data[j].second) stable = false;
        }
    }
    if (stable) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;

}


