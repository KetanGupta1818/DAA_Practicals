// https://onlinegdb.com/EedFoiTOU


#include <bits/stdc++.h>
using namespace std;
int n = 4; //Size of the chessboard , note: keep the size of n small (less than 10)
vector<vector<string>> answer;
bool isPointValid(int i, int j, vector<vector<char>>& queens) {
        for (int x = i-1; x >= 0; x--)
            if (queens[x][j] == 'Q') 
                return false; 
        for (int y = j-1, x = i-1; x >= 0 && y >= 0; x--, y--)
            if (queens[x][y] == 'Q') 
                return false;
        for (int y = j+1, x = i-1; x >= 0 && y < n; x--, y++)
            if (queens[x][y] == 'Q') 
                return false;
        return true;
}
void rec(int level, vector<vector<char>>& queens) {
        if (level == n) {
            vector<string> list;
            for (int i = 0; i < n; i++) {
                string s(queens[i].begin(), queens[i].end());
                list.push_back(s);
            }
            answer.push_back(list);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isPointValid(level, i, queens)) {
                queens[level][i] = 'Q';
                rec(level+1, queens);
                queens[level][i] = '.';
            }
        }
}
int main(){
    vector<vector<char>> queens(n, vector<char>(n,'.'));
    rec(0,queens);
    for(int i=0;i<answer.size();i++){
        cout << "solution number=> " << (i+1) << "\n";
        for(int j=0;j<n;j++) cout << answer[i][j] << "\n";
        cout << endl;
    }
}

