#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet;
        for (auto &word : banned)
        {
            bannedSet.emplace(word);
        }
        int maxFrequency = 0;
        unordered_map<string, int> frequencies;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++)
        {
            if (i < length && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
            }
            else if (word.size() > 0)
            {
                if (!bannedSet.count(word))
                {
                    frequencies[word]++;
                    maxFrequency = max(maxFrequency, frequencies[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word, frequency] : frequencies)
        {
            if (frequency == maxFrequency)
            {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};

int main()
{
    class Solution A;
    vector<int> res;
    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> logs = {{"hit"}};
    string strans = A.mostCommonWord(str, logs);
    return 0;
}
