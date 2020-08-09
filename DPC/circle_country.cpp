#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<double>X(N);

    for (int i = 0; i < N; ++i) {
        cin>>X[i];
    }

    vector<double>Y(N);
    for (int i = 0; i < N; ++i) {
        cin>>Y[i];
    }

    vector<double>R(N);
    for (int i = 0; i < N; ++i) {
        cin>>R[i];
    }

    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int count_start = 0;
    int count_end = 0;

    for (int j = 0; j < N; ++j) {
        if(pow(x1-X[j],2.0)+pow(y1-Y[j],2.0)<pow(R[j],2.0)&&pow(x2-X[j],2.0)+pow(y2-Y[j],2.0)<pow(R[j],2.0)){
            continue;
        }
        if(pow(x1-X[j],2.0)+pow(y1-Y[j],2.0)<pow(R[j],2.0)){
            count_start++;
        }
        if(pow(x2-X[j],2.0)+pow(y2-Y[j],2.0)<pow(R[j],2.0)){
            count_end++;
        }
    }
    cout<<(count_start+count_end)<<endl;
}