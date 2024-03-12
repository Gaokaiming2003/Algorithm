#include<iostream>
#include<vector>

using namespace std;

void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res,\
vector<bool> &cols, vector<bool> &diags1, vector<bool> &diags2){
    if(row == n){
        res.push_back(state);
        return;
    }
    //diags1是主对角线，diags2是次对角线
    //diags1上的元素col-row是个定值范围为[-n+1,n-1]
    //diags2上的元素col+row是个定值范围为[0,2n-1]
    for(size_t col = 0; col < n; col++){
        int diag1 = col - row + n - 1;
        int diag2 = col + row;
        if(!cols[col] && !diags1[diag1] && !diags2[diag2]){
            state[row][col] = "Q";
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            cols[col] = diags1[diag1] = diags2[diag2] = false;
            state[row][col] = "#";
        }
    }
}

vector<vector<vector<string>>> solve(int n){
    vector<vector<string>> state(n,(vector<string>(n, "#")));

    vector<vector<vector<string>>> res;

    vector<bool> cols(n, false);
    vector<bool> diags1(2 * n - 1, false);
    vector<bool> diags2(2 * n - 1, false);

    backtrack(0, n, state, res, cols, diags1, diags2);
    return res;
}


int main(){
    auto res = solve(4);
    for(const vector<vector<string>> &buckets : res){
        for(const vector<string> &bucket : buckets){
            for(const string s: bucket)
                cout << s << ' ';
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }   
}