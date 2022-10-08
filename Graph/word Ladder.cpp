#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bfs(string beginWord, string endWord, map<string, vector<string>> g_map)
    {
        map<string, bool> visited;
        map<string, int> stage;
        stage[beginWord] = 1;
        visited[beginWord] = true;
        queue<string> que;
        que.push(beginWord);
        while (!que.empty())
        {
            string front = que.front();
            que.pop();
            vector<string> v_string = g_map[front];
            for (auto neighbour : v_string)
            {
                if (visited[neighbour] == false)
                {
                    visited[neighbour] = true;
                    stage[neighbour] = 1 + stage[front];
                    que.push(neighbour);
                }
            }
        }
        return stage[endWord];
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        wordList.insert(wordList.begin(), beginWord);
        map<string, vector<string>> g_map;

        for (int i = 0; i < wordList.size(); i++)
        {
            string node = wordList[i];
            for (int j = i + 1; j < wordList.size(); j++)
            {
                string check_word = wordList[j];

                //                 compare two words
                int w_size = check_word.size();
                int count = 0;
                for (int k = 0; k < w_size; k++)
                {
                    if (node[k] == check_word[k])
                        count++;
                }
                if (count >= w_size - 1)
                {
                    // insert in node's neighbour
                    g_map[node].push_back(check_word);
                    g_map[check_word].push_back(node);
                }
            }
        }

        // printing
        // for (int i = 0; i < wordList.size(); i++)
        // {
        //     cout << wordList[i] << " --> ";
        //     vector<string> v_string = g_map[wordList[i]];
        //     for (auto neighbour : v_string)
        //     {
        //         cout << neighbour << " ";
        //     }
        //     cout << endl;
        // }

        return bfs(beginWord, endWord, g_map);
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        string beginWord, endWord;
        cin >> beginWord;
        cin >> endWord;
        vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
        Solution obj = Solution();
        int ans = obj.ladderLength(beginWord, endWord, wordList);
        cout << ans << endl;
        return 0;
    }
}