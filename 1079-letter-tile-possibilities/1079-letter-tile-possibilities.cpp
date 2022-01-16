class Solution {
public:
    vector<int> factorial;
    
    int numTilePossibilities(string tiles) {
        int num = 0;
        init_fact();
        vector<int> count = get_count_arr(tiles);
        vector<int> subcount(26, 0);
        return get_nums(0, tiles, count, subcount) - 1;
    }
    
    vector<int> get_count_arr(const string &tiles) {
        vector<int> count(26, 0);
        for(char c : tiles)
            count[c-'A']++;
        return count;
    }
    
    int get_nums(int id, string &tiles, const vector<int> &count, vector<int> &subcount) {
        if(id == 26) 
            return ans_of(subcount);
        int val = 0;
        for(int i = 0; i <= count[id]; i++) {
            subcount[id] = i;
            val += get_nums(id+1, tiles, count, subcount);
            subcount[id] = 0;
        }
        return val;
    }
    
    int ans_of(const vector<int> &subcount) {
        int l1 = 0, l2 = 1;
        for(int x : subcount) {
            l1 += x;
            l2 *= factorial[x];
            
        }
        return factorial[l1] / l2;
    }
    
    void init_fact() {
        factorial = vector<int>(8, 1);
        for(int i = 2; i <= 7; i++)
            factorial[i] = i * factorial[i-1];
    }
  
    
};