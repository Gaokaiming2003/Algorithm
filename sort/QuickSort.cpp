//还少一个尾递归优化
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
int medianThree(vector<T> & res, int left, int mid, int right){
    //使用异或运算
    //该函数是求res[left], res[right], res[mid]的中间值
    //对快速排序取基准数进行优化
    /* 快速排序在某些输入下的时间效率可能降低。举一个极
    端例子，假设输入数组是完全倒序的，由于我们选择最左端元素作为基准数，那么
    在哨兵划分完成后，基准数被交换至数组最右端，导致左子数组长度为n-1
    、右子数组长度为0。如此递归下去，每轮哨兵划分后都有一个子数组的长度为 
    ，分治策略失效，快速排序退化为“冒泡排序”的近似形式.为了尽量避免这种
    情况发生，我们可以优化哨兵划分中的基准数的选取策略。例如，我们可以
    随机选取一个元素作为基准数。然而，如果运气不佳，每次都选到不理想的基准
    数，效率仍然不尽如人意。需要注意的是，编程语言通常生成的是“伪
    随机数”。如果我们针对伪随机数序列构建一个特定的测试样例，那么快速排序的效率仍然可能劣化。
    为了进一步改进，我们可以在数组中选取三个候选元素（通常为数组的首、
    尾、中点元素），并将这三个候选元素的中位数作为基准数。这样一来，基准数“
    既不太小也不太大”的概率将大幅提升。当然，我们还可以选取更多候选元素，以
    进一步提高算法的稳健性。采用这种方法后，时间复杂度劣化至 O(n^2)
    的概率大大降低。 */
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
        do i++; while(res[i] < med);
        do j--; while(res[j] > med);
        if(i < j){
            swap(res[i], res[j]);
        }
    }
    quickSort(res, left, j);
    quickSort(res, j + 1, right);
}

int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    quickSort(res, 0, res.size() - 1);
    for(auto c : res){
        std::cout << c << ' ';
    }
}