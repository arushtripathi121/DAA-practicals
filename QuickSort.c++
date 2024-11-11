#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

class QuickSort
{
public:
    static int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (arr[j] <= pivot)
            {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    static void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

void generateRandomData(vector<int> &arr, int n)
{
    arr.clear();
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(rand() % 10000);
    }
}

void sortAndMeasureTime(vector<int> &arr)
{
    auto start = high_resolution_clock::now();
    QuickSort::quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken to sort " << arr.size() << " elements: " << duration.count() << " microseconds." << endl;
}

int main()
{
    srand(time(0));

    vector<int> arr;

    for (int n = 1000; n <= 10000; n += 1000)
    {
        generateRandomData(arr, n);
        sortAndMeasureTime(arr);
    }

    return 0;
}
