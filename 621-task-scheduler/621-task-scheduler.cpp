class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        vector<pair<int,int>> freq_sort;
        vector<int> last_time(26, INT_MIN);
        
        for(char task : tasks) 
            freq[task - 'A']++;
        
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] != 0)
                freq_sort.push_back({i, freq[i]});
        }
        
        int t = 0;
        int total_count = 0;
        while(total_count < tasks.size()) {
            auto comp = [](auto &a, auto &b) {return a.second > b.second;};
            sort(freq_sort.begin(), freq_sort.end(), comp);  
            for(auto& el : freq_sort) {
                if(el.second == 0)
                    break;
                if(last_time[el.first] + n < t) {
                    // cout << "\n";
                    el.second--;
                    last_time[el.first] = t;
                    total_count++;
                    // cout << (char)(el.first+'A') << endl;
                    break;
                }
            }
            // cout << ": t = " << t << ", " << total_count << endl;
            t++;
        }
        return t;
    }
};