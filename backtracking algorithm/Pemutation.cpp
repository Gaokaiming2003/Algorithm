/* 输入一个整数数组，其中不包含重复元素，返回所有可能的排列。 */
#include<iostream>
#include<vector>

using namespace std;

void backtrack(vector<int> &state, const vector<int> &nums, vector<bool> &selected, vector<vector<int> > &res){
    if(state.size() == nums.size()){
        //如果状态跟可选择的元素相等时，将结果加入到结果集中，返回
        res.push_back(state);
        return;
    }
    //遍历每一种选择
    for(int i = 0; i < nums.size(); i++){
        if(!selected[i]){
            //尝试，做出选择
            selected[i] = true;
            state.push_back(nums[i]);
            //进行下一轮更新
            backtrack(state, nums, selected, res);
            //回溯
            selected[i] = false;

            state.pop_back();
        }
    }
}

vector<vector<int> > pemutation(vector<int> &nums){
    vector<int> state;
    //selected表示nums中索引为i的数字有无使用。-----false：未使用。true：已使用
    vector<bool> selected(nums.size(), false);
    vector<vector<int> > res;
    backtrack(state, nums, selected, res);
    
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    auto res = pemutation(nums);
    
    for(const vector<int> &bucket : res){
        for(auto c : bucket)
            cout << c << ' ';
        cout << endl;
    }
}