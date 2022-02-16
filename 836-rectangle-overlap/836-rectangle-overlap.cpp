class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(is_intersect(rec1, rec2))
            return true;
        if(contains(rec1, rec2) || contains(rec2, rec1))
            return true;
        if(overlap(rec1, rec2))
            return true;
        return false;
    }
    
    bool is_intersect(vector<int> &A, vector<int> &B) {
        vector<vector<pair<int,int>>> edges_A = get_edges(A);
        vector<vector<pair<int,int>>> edges_B = get_edges(B);
        for(auto& eA : edges_A) {
            for(auto& eB : edges_B) {
                if(intersect(eA, eB) || intersect(eB, eA))
                    return true;
                // cout << eA[0].first << ", " << eA[0].second << "; " << eA[1].first << ", " << eA[1].second << " ---> " << eB[0].first << ", " << eB[0].second << "; " << eB[1].first << ", " << eB[1].second << endl;   
            }
        }
        return false;
    }
    
    bool intersect(const vector<pair<int,int>>& e1, const vector<pair<int,int>>& e2) {
        return e2[0].second > e1[0].second && e2[0].second < e1[1].second && e2[1].first > e1[1].first && e2[0].first < e1[1].first;
        
    }
    
    bool contains(vector<int>& A, vector<int>& B) {
        vector<pair<int,int>> B_points = get_points(B);
        for(auto B_point : B_points) {
            if(!(B_point.first >= A[0] && B_point.first <= A[2] && B_point.second >= A[1] && B_point.second <= A[3]))
                return false;
        }        
        return true;
    }
    
    bool overlap(vector<int>& A, vector<int>& B) {
        if(A[0] == B[0] && A[2] == B[2]) {
            return (A[1] > B[1] && A[1] < B[3]) || (A[3] > B[1] && A[3] < B[3]); 
        }
        else if(A[1] == B[1] && A[3] == B[3]) {
            return (A[0] > B[0] && A[0] < B[2]) || (A[2] > B[0] && A[2] < B[2]); 
        }
        return false;
    }
    
    vector<vector<pair<int,int>>> get_edges(vector<int>& A) {
        vector<vector<pair<int,int>>> ret_vec;
        ret_vec.push_back({{A[0], A[3]}, {A[2], A[3]}});
        ret_vec.push_back({{A[0], A[1]}, {A[2], A[1]}});
        ret_vec.push_back({{A[0], A[1]}, {A[0], A[3]}});
        ret_vec.push_back({{A[2], A[1]}, {A[2], A[3]}});
        return ret_vec;
    }
    
    vector<pair<int,int>> get_points(vector<int>& A) {
        vector<pair<int,int>> ret_vec;
        ret_vec.push_back({A[0], A[3]});
        ret_vec.push_back({A[2], A[3]});
        ret_vec.push_back({A[0], A[1]});
        ret_vec.push_back({A[2], A[1]});
        return ret_vec;
    }
    
};

/*
[0,0,2,2]
[1,1,3,3]
[0,0,1,1]
[1,0,2,1]
[0,0,1,1]
[2,2,3,3]
[108, -436, 417, 534]
[520, -436, 830, 534]
[10800, -2830, 15800, 1000]
[10800, 2000, 15800, 5420]
[0, 0, 15800, 1000]
[-5,-10,200000,200000]
[-400,-800, -700, 600]
[-200, -400, 1000, 300]
[0,0,100,200]
[0,0,300, 500]

*/