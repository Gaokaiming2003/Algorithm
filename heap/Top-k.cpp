/* Top-k问题：
    给定一个长度为n的无序数组nums,请返回
    数组中最大的k个元素。
 */
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

/* 遍历 */
vector<int> method_one(vector<int> &nums, int k){
    vector<int> res;
    int count = 0;
    int size = nums.size();
    for(int i = 0; i < size; i++){
        if(count == k)
            break;
        int max = 0;
        for(int j = 1; j < nums.size(); j++){
                if(nums[max] < nums[j])
                    max = j;
        }
        swap(nums[max], nums[nums.size() - 1]);
        res.push_back(nums[nums.size() - 1]);
        nums.pop_back();
        count++;
    }
    return res;
}

template<typename T>
int medianThree(vector<T> & res, int left, int mid, int right){
    if(res[left] < res[mid] ^ res[left] < res[right])
        return left;
    else if(res[right] < res[mid] ^ res[right] < res[left])
        return right;
    else 
        return mid;
}
template<typename T>
void quickSort(vector<T> &res, int left, int right){
    if(left >= right){
        return;
    }
    int i = left - 1;
    int j = right + 1;
    int mid = (left + right) >> 1;
    int med = res[medianThree(res, left, mid, right)];
    while(i < j){
        do i++; while(res[i] > med);
        do j--; while(res[j] < med);
        if(i < j){
            swap(res[i], res[j]);
        }
    }
    quickSort(res, left, j);
    quickSort(res, j + 1, right);
}
/* 排序 */
vector<int> method_two(vector<int> &nums, int k){
   quickSort(nums, 0, nums.size() - 1);
   vector<int> res(nums.begin(), nums.begin() + k);
   return res;
}

/* 堆 */
priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int> &nums, int k) {
    // 初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> heap;
    // 将数组的前 k 个元素入堆
    for (int i = 0; i < k; i++) {
        heap.push(nums[i]);
    }
    // 从第 k+1 个元素开始，保持堆的长度为 k
    for (int i = k; i < nums.size(); i++) {
        // 若当前元素大于堆顶元素，则将堆顶元素出堆、当前元素入堆
        if (nums[i] > heap.top()) {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    return heap;
}

int main(){
    vector<int> nums{1,7,2,3,6};
    auto res = topKHeap(nums, 4);
    
    while(!res.empty()){
        cout << res.top() << ' ';
        res.pop();
    }
}