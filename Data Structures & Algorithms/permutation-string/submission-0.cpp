class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())return false;
        vector<int>s1Count(26,0);
        vector<int>s2Count(26,0);
        
        for(int i =0;i<s1.length();i++){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }

        if(s1Count == s2Count)return true;
        int left = 0;
        for(int right = s1.length();right < s2.length();right++){
            s2Count[s2[right]-'a']++;
            s2Count[s2[left]-'a']--;
            left++;

            if(s1Count == s2Count)return true;
        }
       return false;
    }
};
