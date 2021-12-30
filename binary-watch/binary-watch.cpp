class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> leds(10, 0);
        return gen_time(0, turnedOn, leds);
    }
    
    vector<string> gen_time(int id, int &turnedOn, vector<int> &leds) {
        vector<string> vec;
        if(turnedOn == 0) {
            string time = get_time(leds);
            if(time != "")
                vec.push_back(get_time(leds));
            return vec;
        }
        if(id == leds.size())
            return vec;
        
        turnedOn--;
        leds[id] = 1;
        vec = gen_time(id+1, turnedOn, leds);
        turnedOn++;
        leds[id] = 0;
        vector<string> vec1 = gen_time(id+1, turnedOn, leds);
        vec.insert(vec.end(), vec1.begin(), vec1.end());
        return vec;
    }
    
    string get_time(vector<int> &leds) {
        int hr_int = leds[3]*8 + leds[2]*4 + leds[1]*2 + leds[0];
        int min_int = leds[9]*32 + leds[8]*16 + leds[7]*8 + leds[6]*4 + leds[5]*2 + leds[4];
        if(hr_int >= 12 || min_int >= 60)
            return "";
        string hr = to_string(hr_int);
        string min = to_string(min_int);
        min = min.size() == 1 ? "0" + min : min;
        return hr +":"+min;
    }
};