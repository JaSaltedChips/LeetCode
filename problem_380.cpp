/*
380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet {
public:
    std::unordered_map<int, int> maps; // value -> index
    std::vector<int> value;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(maps.find(val) != maps.end())
            return false; // item is already present
        
        value.push_back(val);
        maps[val] = static_cast<int>(value.size())-1;
        return true;
    }
    
    bool remove(int val) {
        if (maps.find(val) == maps.end())
            return false;

        int index = maps[val];
        int lastVal = value.back();

        value[index] = lastVal;
        value.pop_back();

        maps[lastVal] = index;   // update BEFORE erase
        maps.erase(val);         // if val==lastVal, write then erase is correct
        return true;             // erase then write would silently reinsert it
    }
    
    int getRandom() {
        int index = rand() % static_cast<int>(value.size());
        return value[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
