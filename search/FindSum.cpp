#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

vector<int> find(vector<int> &nums, int target){
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        if(map.find(target - nums[i]) != map.end())
            return {i, map[target - nums[i]]};
        map.emplace(nums[i] ,i);
    }
    return {};
}