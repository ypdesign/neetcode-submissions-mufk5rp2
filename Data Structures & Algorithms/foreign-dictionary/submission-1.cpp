class Solution {
public:
    string foreignDictionary(vector<string>& words) {
      int n=words.size();
      vector<vector<bool>>adj(26,vector<bool>(26,false));
      vector<int>indegree(26);
      vector<bool>vis(26);
      string ans;
      for(auto s: words){
        for(auto c : s){
            vis[c-'a']=true;
        }
      }
      for(int i=0;i<n-1;i++){
          string w1=words[i];
          string w2=words[i+1];
          for(int j=0;j<min(w1.size(),w2.size());j++){
              if(w1[j] != w2[j]){
                if(!adj[w1[j]-'a'][w2[j]-'a']){
                    adj[w1[j]-'a'][w2[j]-'a']=true;
                    indegree[w2[j]-'a']++;
                }
                break;
              }
          }
              if(w1.size() > w2.size() && w1.substr(0,w2.size()) == w2)
                return " ";
      }
      queue<int>q;
      for(int i=0;i<26;i++){
        if(indegree[i]== 0 && vis[i]){
            q.push(i);
        }
      }
      while(!q.empty()){
         int node=q.front();
         q.pop();
         ans+=(char)(node+'a');
         for(int i=0;i<26;i++){
         if(adj[node][i]){
            indegree[i]--;
            if(indegree[i] == 0 && vis[i])
                q.push(i);
         }
         }
      }
      int total=0;
      for(int i=0;i<26;i++){
        if(vis[i])total++;
      }
      if(ans.size() != total) return " ";
      return ans;
    }
};
