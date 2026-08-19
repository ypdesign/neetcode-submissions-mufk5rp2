class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int temp=i;
            int sol=0;
            while(temp!=0){
              sol+= temp&1;
              temp >>=1;
            }
            ans.push_back(sol);
        }
        return ans;
    }
};
