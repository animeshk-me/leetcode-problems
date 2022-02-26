class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks) 
            freq[task - 'A']++;
        
        int max_freq = 0;
        for(int f : freq)
            max_freq = max(max_freq, f);
    
        int count = 0;    
        for(int f : freq)
            count = f == max_freq ? count + 1 : count;
        
        return max((int)tasks.size(), (max_freq-1) * n + max_freq + count - 1);
    }
};