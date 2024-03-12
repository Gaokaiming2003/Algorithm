/* 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。给定数组可能包含重复元素，
每个元素只可被选择一次。请以列表形式返回这些组合，列表中不应包含重复组合。 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void backtrack(vector<int> &state, vector<vector<int>> &res, int start, int target, vector<int> &choices){
    //子集和等于target时，记录解
    if(target == 0){
        res.push_back(state);
        return;
    }
    //遍历所有选择
    //剪枝二：从start开始遍历，避免生成重复子集
    //剪枝三：从start开始遍历，避免选择同一元素
    for(size_t i = start; i < choices.size(); i++){
        // 剪枝一：若子集和超过target，因为choices是递增，所以i之后的都不满足
        int choice = choices[i];
        if(target - choice < 0)
            break;

            //剪枝四：如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
        if(i > start && choices[i] == choices[i - 1])
            continue;
        
        state.push_back(choice);
        //从i+1开始，因为不能重复选择同一位置的元素
        backtrack(state, res, i + 1, target - choice, choices);

        state.pop_back();
    }
}

vector<vector<int>> Subset(vector<int> &nums, int target){
    vector<int> state;
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    backtrack(state, res, 0, target, nums);

    return res;
}

int main(){
    vector<int> nums{1,2,2,3,4};
    auto res = Subset(nums, 4);
    for(const auto &bucket : res){
        for(auto c : bucket)
            cout << c << ' ';
        cout << endl;
    }
}