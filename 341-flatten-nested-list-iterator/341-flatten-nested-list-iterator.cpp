/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int x_i;
    vector<NestedInteger> nested_list;
    NestedIterator * active_itr;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nested_list = nestedList;
        x_i = 0;
        active_itr = NULL;
    }
    
    int next() {
        if(nested_list[x_i].isInteger()){
            active_itr = NULL;
            return nested_list[x_i++].getInteger();
        }
        return active_itr->next();
    }
    
    bool hasNext() {
        if(x_i == nested_list.size())
            return false;
        while(x_i < nested_list.size()) {
            if(nested_list[x_i].isInteger())
                return true;
            if(active_itr == NULL)
                active_itr = new NestedIterator(nested_list[x_i].getList());
            if(active_itr->hasNext())
                return true;
            active_itr = NULL;            
            x_i++;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */