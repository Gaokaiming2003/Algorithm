#define SIZE 100
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Pair{
    public:
        int key;
        string val;
        Pair(int key, string val){
            this -> key = key;
            this -> val = val;
        }
};

class ArrayHashMap
{
private:
    vector<Pair *> buckets;
public:
    ArrayHashMap(){
        buckets = vector<Pair*>(SIZE);
    }
    ~ArrayHashMap(){
        for(const auto &bucket : buckets){
            delete bucket;
        }
        buckets.clear();
    }
    int hashFunc(int key){
        int index = key % SIZE;
        return index;
    }

    string get(int key){
        int index = hashFunc(key);
        Pair* pair = buckets[index];
        if(pair == nullptr) return "";
        return pair -> val;
    }

    void push(int key, string value){
        Pair* pair = new Pair(key, value);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    void remove(int key){
        int index = hashFunc(key);
        delete buckets[index];   //delete之后只是删除了指针所指的内存的值
        buckets[index] = nullptr; //而指针本身没有被删除，指针会指向一个其他的位置
        //所以一定要设置为空指针 
    }

    vector<Pair *> getAllKeyValue(){
        vector<Pair *> set;
        for(Pair* pair : buckets) {
            if(pair != nullptr)
                set.push_back(pair);
        }
        return set;
    }

    vector<int> getAllKey(){
        vector<int> set;
        for(Pair* pair : buckets){
            if(pair != nullptr){
                set.push_back(pair -> key);
            }
        }
        return set;
    }

    vector<string> getAllValue(){
        vector<string> set;
        for(Pair* pair : buckets){
            if(pair != nullptr){
                set.push_back(pair -> val);
            }
        }
        return set;
    }

    void printHashMap(){
        for(Pair* pair : buckets){
            cout << pair -> key << " -> " << pair -> val << endl;
        }
    }
};
