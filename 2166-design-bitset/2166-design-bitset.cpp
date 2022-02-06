class Bitset {
public:
    vector<bool> my_bitset;
    vector<bool> my_flip_bitset;
    int c;
    Bitset(int size) {
        my_bitset = vector<bool>(size, false);
        my_flip_bitset = vector<bool>(size, true);
        c = 0;
    }
    
    void fix(int idx) {
        if(!my_bitset[idx]) {
            my_bitset[idx] = true;
            my_flip_bitset[idx] = false;
            c++;
        }
    }
    
    void unfix(int idx) {
        if(my_bitset[idx]) {
            my_bitset[idx] = false;
            my_flip_bitset[idx] = true;
            c--;
        }
    }
    
    void flip() {
        my_bitset.swap(my_flip_bitset);
        c = my_bitset.size() - c;
    }
    
    bool all() {
        return c == my_bitset.size();
    }
    
    bool one() {
        return c > 0;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
        string x = "";
        for(bool is_set : my_bitset) {
            x += is_set ? '1' : '0';
        }
        return x;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */