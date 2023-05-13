/*
For performing multiplication of 4*4 matrix, 4 threads are created.
Each thread calculates the answer of its particular row
 Like thread number 0, fills row number 0 of the answer matrix
*/


#include<bits/stdc++.h>
using namespace std;
//Create the first matrix a
vector<vector<int>> a = {{1,3,2,4},{2,3,4,5},{9,3,2,30},{9,9,3,2}};
//Create the second matrix b
vector<vector<int>> b = {{9,4,3,2},{2,3,4,2},{4,3,5,66},{9,4,3,2}};
//Create a matrix with all zeros to store the answer
vector<vector<int>> ans(4,vector<int>(4,0));
class Multiplier {
public:
    int i; //Row number
    Multiplier(int i): i(i) {}
    void operator()() { //Matrix multiplication for row number i
        for (int j = 0; j < 4; j++) { 
            for (int k = 0; k < 4; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
};
int main() {
    thread t[4]; //Initialise an array of 4 threads
    for (int i = 0; i < 4; i++) t[i] = thread(Multiplier(i)); 
    for (int i = 0; i < 4; i++) t[i].join();
    cout << "answer matrix:" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
