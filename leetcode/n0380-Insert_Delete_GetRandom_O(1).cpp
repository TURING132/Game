#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> map; // val : index in array
    vector<int> values;
    int size = 0;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        values.push_back(val);
        map[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        // exchange palce with the last element
        int index = map[val];
        int last = values.back();
        values[index] = last;
        map[last] = index;
        values.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};
