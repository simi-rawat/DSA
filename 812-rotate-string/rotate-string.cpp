class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        if(s == goal){
            return true ;
        }
        string ans;
        int k;
        for (int i = 0; i < s.size(); i++) {
            ans.clear();

            if (s[i] == goal[0]) {

                for (int j = i; j < s.size(); j++)
                    ans.push_back(s[j]);

                for (int j = 0; j < i; j++)
                    ans.push_back(s[j]);

                if (ans == goal)
                    return true;
            }
        }
        return 0;
        
    }
};