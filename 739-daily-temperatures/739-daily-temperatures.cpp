class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        // srand(time(0));
        // for(int i = 0; i < 1e5; i++) {
        //     cout << rand() % 71 + 30 << ", ";
        // }
        for(int i = temperatures.size() - 2; i >= 0; i--) {
            int j = i + 1;
            bool got = false;
            while(temperatures[j] <= temperatures[i]) {
                if(answer[j] == 0) {
                    answer[i] = 0;
                    got = true;
                    break;
                }
                j = j + answer[j];
            }
            if(!got)
                answer[i] = j - i;
        }
        return answer;
    }
    /*
    [73,74,75,71,69,72,76,73]
[30,40,50,60]
[30,60,90]
[37,51,36,52,35,53,55,34,54]
    */
};