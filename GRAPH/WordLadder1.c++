#include <unordered_set>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair<string, int>>q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++)
            {
                char initial=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())//this is jjust to check if the word is present in the given world List
                    {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i]=initial;
            }
        }
        return 0;
    }
};