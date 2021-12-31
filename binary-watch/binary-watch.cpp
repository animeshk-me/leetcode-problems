class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        bitset<10> leds;
        vector<string> strings;
        gen_time(0, turnedOn, leds, strings);
        return strings;
    }
    
    void gen_time(int id, int &turnedOn, bitset<10> &leds, vector<string> &strings) {
        if(turnedOn == 0) {
            string time = get_time(leds);
            if(time != "invalid")
                strings.push_back(time);
            return;
        }
        if(id == leds.size())
            return;
        turnedOn--;
        leds[id] = 1;
        gen_time(id+1, turnedOn, leds, strings);
        turnedOn++;
        leds[id] = 0;
        gen_time(id+1, turnedOn, leds, strings);
    }
    
    string get_time(bitset<10> &leds) {
        int hr_int = leds[3]*8 + leds[2]*4 + leds[1]*2 + leds[0];
        int min_int = leds[9]*32 + leds[8]*16 + leds[7]*8 + leds[6]*4 + leds[5]*2 + leds[4];
        if(hr_int >= 12 || min_int >= 60)
            return "invalid";
        string hr = to_string(hr_int);
        string min = to_string(min_int);
        min = min.size() == 1 ? "0" + min : min;
        return hr +":"+min;
    }
};