class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        // srand(time(0));
        // for(int i = 0; i < 1e5; i++) {
        //     cout << rand() % 71 + 30 << ", ";
        // }
        stack<int> S;
        for(int i = 0; i < temperatures.size(); i++) {
            while(!S.empty() && temperatures[S.top()] < temperatures[i]) {
                answer[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
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