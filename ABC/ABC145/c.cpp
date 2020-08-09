#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>

#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<vector <int> > XY (N, vector<int>(2, 0));

    for (int i = 0; i < N; ++i) {
        cin >> XY[i][0] >> XY[i][1];
    }
    int distance_num;
    distance_num=0;
    for (int n = 0; n < N-1; ++n) {
        distance_num += n+1;
    }
    vector<vector<double> >distance(N,vector<double>(N));
    double ans;
    ans =0;

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j <N ; ++j) {
            distance[j][i] = sqrt(pow(XY[i][0]-XY[j][0],2)+pow(XY[i][1]-XY[j][1],2));
            distance[i][j] = sqrt(pow(XY[i][0]-XY[j][0],2)+pow(XY[i][1]-XY[j][1],2));
        }
    }
    vector<int>v(N);
    iota(v.begin(),v.end(),0);
    double sum;
    do{
        sum = 0;
        for(int k = 0; k<N-1;++k){
            sum+=distance[v[k]][v[k+1]];
        }
        ans += sum;
    }while(next_permutation(v.begin(),v.end()));

    int Nk;
    Nk=1;
    for (int m = 0; m < N; ++m) {
        Nk *= N-m;
    }
    ans =ans/Nk;
    printf("%.10f\n",ans);

}
