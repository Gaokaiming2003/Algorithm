#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void backtrack(vector<int> &state, vector<int> &choices, int start, int target, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(state);
        return;
    }

    for(size_t i = start; i < choices.size(); i++){
        int choice = choices[i];
        if(target - choice < 0)
            break;
        
        state.push_back(choice);
        backtrack(state, choices, i, target - choice, res);
        
        state.pop_back();
    }
}
vector<vector<int>> SubSet(vector<int> &nums, int target){
    vector<int> state;
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    backtrack(state, nums, 0, target, res);
    return res;
}

int main(){
    vector<int> nums{1,2,3,4,5,6};
    auto res = SubSet(nums, 5);
    for(const vector<int> & bucket : res){
        for(auto c : bucket)
            cout << c << ' ';
        cout << endl;
    }
}