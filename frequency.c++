#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findFrequency(const vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
    {
        freq[num]++;
    }

    for (const auto &pair : freq)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4};
    findFrequency(arr);
    return 0;
}
