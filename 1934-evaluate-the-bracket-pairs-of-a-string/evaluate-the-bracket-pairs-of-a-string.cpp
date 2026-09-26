class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
   
    unordered_map<string,string>m;
      for (const auto& row : knowledge) {
        if (row.size() >= 2) {
            m[row[0]] = row[1];
        }
    }
    string ans="";

    string word="";
    int counter=0;
    for(auto ch :s){
        if(ch=='('){
            counter=1;

        }
        else if(ch==')'){
          counter=0;
            if(m.find(word)!=m.end()){
                ans+=m[word];
            }
            else{
                ans+='?';
            }
            word="";
        } 
        else{
            if(counter){
                word+=ch;
            }
            else{
                ans+=ch;
            }
        }
    }
    return ans;
    }

};