#include <bits/stdc++.h>
using namespace std;


int count(int number,vector<string> &relation,vector<int> &memo,int N) {
    for (int i = 0; i < N; ++i) {
        if (relation[number][i] == 'Y') {
            if (memo[i] == 0) {
                memo[number] += count(i,relation,memo,N);
            } else {
                memo[number] += memo[i];
            }
        }

    }
    if (memo[number]==0) {
        memo[number] += 1;
    }
    return memo[number];
}

int main() {
    int N;
    cin>>N;
    vector<string> relation(N);
    vector<int>memo(N,0);


    for (int i = 0; i < N; ++i) {
        cin>>relation[i];
    }


    for (int j = 0; j < N; ++j) {
        if(memo[j]==0){
            memo[j] = count(j,relation,memo,N);
        }
    }

    int ans=0;
    for (int k = 0; k < N; ++k) {
        ans +=memo[k];
    }
    cout<<ans<<endl;
}