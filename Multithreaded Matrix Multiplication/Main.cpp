#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a = {{1,3,2,4},{2,3,4,5},{9,3,2,30},{9,9,3,2}};
vector<vector<int>> b = {{9,4,3,2},{2,3,4,2},{4,3,5,66},{9,4,3,2}};
vector<vector<int>> ans(4,vector<int>(4,0));
class Multiplier {
public:
    int i;
    Multiplier(int i): i(i) {}
    void operator()() {
        for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) ans[i][j] += a[i][k] * b[k][j];
    }
};
int main() {
    thread t[4];
    for (int i = 0; i < 4; i++) t[i] = thread(Multiplier(i));
    for (int i = 0; i < 4; i++) t[i].join();
    cout << "answer matrix:" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
