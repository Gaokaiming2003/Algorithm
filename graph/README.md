# 图(graph)

## 定义

「图 graph」是一种非线性数据结构，由「顶点 vertex」和「边 edge」组成。我们可以将图$G$抽象地表示为一组顶点$V$和一组边$E$ 的集合。以下示例展示了一个包含 5 个顶点和 7 条边的图。![alt text](img/example.png)

如果将顶点看作节点，将边看作连接各个节点的引用（指针），我们就可以将图看作一种从链表拓展而来的数据结构。如图 9-1 所示，相较于线性关系（链表）和分治关系（树），网络关系（图）的自由度更高，因而更为复杂。
![alt text](img/linkedlist_tree_graph.png)

## 图的常见类型与术语

$$
    图
    \begin{cases}
        有向图(directed \space graph)\\
        无向图(undirected\space graph)
    \end{cases}
$$

## 图的表示

### 邻接矩阵

$$
    设图的顶点数量为n, ``邻接矩阵 adjacency\space matri''使用\\一个n \times n大小的矩阵来表示图，每一行(列)代表一个顶点，\\矩阵元素代表边，用1或0表示两个顶点之间是否存在边。
$$