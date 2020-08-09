#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N,M;
    long long L;
    cin>>N>>M>>L;
    vector<vector <long long> >load(M,vector<long long>(3,0));
    for (int i = 0; i < M; ++i) {
        cin>>load[i][0]>>load[i][1]>>load[i][2];

    }
    int Q;
    cin>>Q;
    vector<vector <int> > queri (Q,vector<int>(2,0));
    for (int j = 0; j < Q; ++j) {
        cin>>queri[j][0]>>queri[j][1];
    }

    vector<vector <long long> > long (N,vector<long long>(N,-1));


}
