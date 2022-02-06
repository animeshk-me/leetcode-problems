class Bitset {
public:
    string main_str;
    string sub_str;
    int c;
    Bitset(int size) {
        main_str = string(size, '0');
        sub_str = string(size, '1');
        c = 0;
    }
    
    void fix(int idx) {
        if(main_str[idx] == '0') {
            main_str[idx] = '1';
            sub_str[idx] = '0';
            c++;
        }
    }
    
    void unfix(int idx) {
        if(main_str[idx] == '1') {
            main_str[idx] = '0';
            sub_str[idx] = '1';
            c--;
        }
    }
    
    
    void flip() {
        main_str.swap(sub_str);
        c = main_str.size() - c;
    }
    
    bool all() {
        return c == main_str.size();
    }
    
    bool one() {
        return c > 0;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
        return main_str;
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