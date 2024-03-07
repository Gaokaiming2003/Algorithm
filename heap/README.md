# 堆 (heap)

## 定义

[堆heap]是一种满足特定条件的[完全二叉树](../tree/Tree.md#完全二叉树)。

* 大顶堆 max heap：任意节点的值$\ge$其子节点的值。
* 小顶堆 min heap：任意节点的值$\le$其子节点的值。
  ![alt text](img/min_heap_and_max_heap.png)

## 特性

* 最底层节点靠左填充，其他层的节点都被填满。
* 我们将二叉树的根节点称为“堆顶”，将底层最靠右的节点称为“堆底”。
* 对于大顶堆（小顶堆），堆顶元素（根节点）的值是最大（最小）的。

堆通常用于实现优先队列，大顶堆相当于元素按从大到小的顺序出队的优先队列。
从使用角度看，我们可以将“优先队列”和“堆”看成等价的数据结构。

## STL的堆（优先队列）

```C++
//初始化小顶堆
priority_queue<int, vector<int>, greater<int>> min_heap;
//初始化大顶堆
priority_queue<int, vector<int>, less<int>> max_heap;
//元素入堆
max_heap.push(1);
max_heap.push(2);
max_heap.push(3);
max_heap.push(4);
max_heap.push(5);
max_heap.push(6);

min_heap.push(1);
min_heap.push(2);
min_heap.push(3);
min_heap.push(4);
min_heap.push(5);
min_heap.push(6);
min_heap.push(1);

//获取堆顶元素
int peek = min_heap.top();

//元素出堆
max_heap.pop();
min_heap.pop();

//获取堆大小
int size = max_heap.size();

//判空
bool isEmpty = min_heap.empty();

vector<int> input{1,2,3,4,5};
priority_queue<int, vector<int>, greater<int> > min_heap(input.begin(), input.end());
```

## 堆的常见应用

* 优先队列：堆通常作为实现优先队列的首选数据结构，其入队和出队操作的时间复杂度均为$O(log n)$,而建队操作为$O(n)$.
* 堆排序
* 获取最大的k个元素
    
## 总结

* 堆是一颗完全二叉树，根据成立条件可分为大顶堆和小顶堆。
* 优先队列的定义是具有出队优先级的队列，通常使用堆来实现。
* 堆的常用操作及其对应的时间复杂对包括：元素入堆$O(log n)$、堆顶元素出堆$O(long n)$、访问堆顶元素$O(1)$.
* 完全二叉树非常适合用数组表示，因此通常使用数组来存储堆。
* 堆化操作用于维护堆的性质，在入堆和出堆操作中都会用到。
* 输入n个元素并建堆的时间复杂度可以优化至$O(n)$.
* Top-k是一个经典算法问题，可以使用堆数据结构高效解决，时间复杂度为$O(nlog k)$.

数据结构的“堆”和内存中的“堆”不是一个概念，只是碰巧都叫“堆”。计算机系统内存中的堆是动态内存分配的一部分，程序在运行时可以使用它来存储数据。程序可以请求一定量的堆内存，用于存储如对象和数组等复杂结构。当这些数据不再需要时，程序需要释放这些内存，以防止内存泄漏。相较于栈内存，堆内存的管理和使用需要更谨慎，使用不当可能会导致内存泄漏和野指针等问题。

