#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void backtrack(vector<int> &state, vector<int> &choices, vector<bool> &selected, vector<vector<int> > &res){
    if(state.size() == choices.size()){
        res.push_back(state);
        return;
    }
    //包含重复元素的添加一个元素使用哈希表
    unordered_set<int> duplicated;
    for(int i = 0; i < choices.size(); i++){
        int choice = choices[i];
        //剪枝：不允许重复选择元素并且不允许重复选择相等元素
        if(!selected[i] && duplicated.find(choice) == duplicated.end()){
            selected[i] = true;
            duplicated.emplace(choice);
            state.push_back(choice);
            backtrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}

vector<vector<int> > pemutationIncludeRepeat(vector<int> &nums){
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int> > res;
    backtrack(state, nums, selected, res);
    return res;
}

int main(){
    vector<int> nums = {1,2,2};
    auto res = pemutationIncludeRepeat(nums);
    for(const vector<int> &bucket : res){
        for(auto c : bucket)
            cout << c << ' ';
        cout << endl;
    }
}