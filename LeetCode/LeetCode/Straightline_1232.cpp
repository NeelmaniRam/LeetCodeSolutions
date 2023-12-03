class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        double slope=(double)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        for(int i=2;i<coordinates.size();i++){
            vector<int> a=coordinates[i], b=coordinates[i-1];
            if( slope != (double)(a[1]-b[1])/(a[0]-b[0])){
                return false;
            }


        }
        return true;
        
    }
};