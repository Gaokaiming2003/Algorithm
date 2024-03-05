#include<iostream>
#include<vector>
#include"Pair.h"

using namespace std;

class HashMapVector
{
private:
    int size;
    int capacity;
    double loadThres;
    double extendRatio;
    vector<vector<Pair* >> buckets;
public:
    HashMapVector() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2){
        buckets.resize(capacity);
    }
    ~HashMapVector(){
        for(auto& bucket : buckets){
            for(Pair* pair : bucket){
                delete pair;
            }
        }
    }
    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }
    bool isEmpty(){
        return getSize() == 0;
    }
    double getLoadFactor(){
        return (double) size / (double) capacity;
    }
    string get(int key){
        int index = hashFunc(key);
        for(Pair* pair : buckets[index]){
            if(pair -> key == key){
                return pair -> val;
            }
        }
        return "";
    }
    int hashFunc(int key){
        return key % capacity;
    }
    void extend(){
        auto buckets_tmp = buckets;
        capacity *= extendRatio;
        size = 0;
        buckets.clear();
        buckets.resize(capacity);
        for(auto &bucket : buckets_tmp){
            for(Pair* pair : bucket){
                put(pair -> key, pair -> val);
            }
        }
    }
    void put(int key, string val){
        if(getLoadFactor() > loadThres) {
            extend();
        }
        int index = hashFunc(key);
        for(Pair* pair : buckets[index]){
            if(pair -> key == key){
                pair -> val = val;
                return;
            }
        }
        buckets[index].push_back(new Pair(key, val));
        size++;
    }
    bool find(int key, string val){
        if(size == 0) return false;
        int index = hashFunc(key);
        for(Pair* pair : buckets[index]){
            if(pair -> val == val){
                return true;
            }
        }
        return false;
    }
    bool find(int key){
        if(size == 0) return false;
        int index = hashFunc(key);
        for(Pair* pair : buckets[index]){
            if(pair -> key == key) return true; 
        }
        return false;
    }
    void remove(int key){
        if(!find(key)) return;
        int index = hashFunc(key);
        auto& bucket = buckets[index];
        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i] -> key == key){
                Pair* tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }
    void print(){
        for(auto& bucket : buckets){
            for(Pair* pair : bucket){
                if(pair -> key == NULL) continue;
                cout << "[" << pair -> key << "->" << pair->val << "]  ";
            }
            cout << endl;
        }
    }
};
int main(){
    HashMapVector* map = new HashMapVector();

    map -> put(1,"2");
    map -> put(2,"2");
    map -> put(3,"2");
    map -> put(4,"2");
    map -> put(5,"2");
    map -> put(2,"2");
    map -> put(3,"2");
    map -> put(10,"2");

    map->print();
        cout << endl;
    map->remove(1);
        cout << endl;
    map->print();
        cout <<endl;
    return 0;    
}

