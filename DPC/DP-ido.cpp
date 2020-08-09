#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int>donation(N);
    vector<int>dp(N,0);
    vector<int>dp1(N,0);
    vector<int>dp2(N,0);
    for (int j = 0; j < N; ++j) {
        cin>>donation[j];
    }

    dp[0] = donation[0];
    for (int i = 2; i < N-1; ++i) {
        dp[i] = max(dp[i - 2] + donation[i], dp[i]);

        if (i - 3 >= 0) {
            dp[i] = max(dp[i-3]+donation[i],dp[i]);
        }
    }
    dp1[1] = donation[1];
    for (int i = 3; i < N; ++i) {
        dp1[i] = max(dp1[i - 2] + donation[i], dp1[i]);

        if (i - 3 >= 0) {
            dp1[i] = max(dp1[i-3]+donation[i],dp1[i]);
        }
    }

    dp2[2] = donation[2];
    for (int i = 4; i < N; ++i) {

        dp2[i] = max(dp2[i - 2] + donation[i], dp2[i]);

        if (i - 3 >= 0) {
            dp2[i] = max(dp2[i-3]+donation[i],dp2[i]);
        }
    }


    cout<<max(dp2[N-1],max(dp1[N-1],dp[N-2]))<<endl;

}