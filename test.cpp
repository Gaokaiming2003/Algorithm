#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> res;
vector<vector<int>> ans;
bool book[10] = {1};
void dfs(int n, int size){
    if(n == size){
        ans.push_back(res);
        return;
    }
    for(int i = 1; i <= size; i++)
    if(book[i] == 1){
        res.push_back(i);
        book[i] = 0;
        dfs(i + 1, size);
        res.pop_back();
        book[i] = 1;
    } 
}

int main()
{
    int num;
    cin >> num;
    dfs(1, num + 1);
    
    for(vector<int>& bucket : ans){
        for(auto c : bucket){
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}