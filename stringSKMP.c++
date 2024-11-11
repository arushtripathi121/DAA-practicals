#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP_Search(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    cout << "Finding all occurrences of the pattern in the string:\n";
    KMP_Search(text, pattern);
    return 0;
}
