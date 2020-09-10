#include <algorithm>
using namespace std;
int findFrequent(int arr[], int n)
{
    sort(arr, arr + n);
    int previous = arr[0];
    int popular = arr[0];
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == previous)
            count++;
        else {
            if (count > maxCount) {
                popular = arr[i-1];
                maxCount = count;
            }
            previous = arr[i];
            count = 1;
        }
    }

    return count > maxCount ? arr[n-1] : popular;
}
