#include<iostream>
#include<vector>

using namespace std;

class GraphAdjacencyMatrix
{
private:
    vector<int> vertices; //顶点列表，元素代表“顶点值”，索引代表“顶点索引”
    vector<vector<int> > adj_mat; //邻接矩阵，行列索引对应“顶点索引”，n行n列
    /* adj_mat[i][j]中的i跟vertices[i]的i是相同的，邻接矩阵里的下标只是顶点的一个映射
        必须是连续的 */
public:
    GraphAdjacencyMatrix(const vector<int> &vertices, const vector<vector<int> > &edges){
        for(int val : vertices){
            addVertex(val);
        }
            //edges是一个n行2列的矩阵，其中n为边的数量
        for(const vector<int> &edge : edges){
            addEdge(edge[0], edge[1]);
        }
    }
    
    int getSize(){
        return vertices.size();
    }

    void addVertex(int vertex){
        //向顶点列表中添加顶点
        vertices.push_back(vertex);
        //向邻接矩阵中添加一行
        adj_mat.emplace_back(vector<int>(getSize(), 0));
        //向邻接矩阵中添加一列
        for(vector<int> &col : adj_mat){
            col.push_back(0);
        }
    }

    void addEdge(int i, int j){
        if(i < 0 || j < 0 || i > getSize() || j > getSize() || i == j){
            /* 无向图 不包括环 */
            throw out_of_range("顶点不存在");
        }
        /* 无向图中，邻接矩阵满足对称 */
        adj_mat[i][j] = 1;
        adj_mat[j][i] = 1;
    }

    void removeVertex(int val){
        if(val >= getSize())
            throw out_of_range("无此顶点");
        /* 删除顶点列表中的顶点 */
        vertices.erase(vertices.begin() + val);
        /* 删除行 */
        adj_mat.erase(adj_mat.begin() + val);
        /* 删除列 */
        for(vector<int> &col : adj_mat)
            col.erase(col.begin() + val);
    }

    void removeEdge(int i, int j){
        if(i < 0 || j < 0 || i > getSize() || j > getSize() || i == j){
            throw out_of_range("边不存在");
        }
        adj_mat[i][j] = 0;
        adj_mat[j][i] = 0;
    }

    void print(){
        cout << "顶点列表 = " ;
        for(auto c : vertices){
            cout << c << ' ';
        }
        cout << endl;
        cout << "邻接矩阵 = ";
        for(vector<int> & row : adj_mat)
            for(auto c : row)
                cout << c << ' ';
            cout << endl;
    }
};
