#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(const vector<double>& arr, double target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) { 
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        } else { 
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
    }

    return -1;
}

int main() {
    double target;
    int n;

    cout << "Enter the target to search: ";
    cin >> target;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<double> arr(n);

    cout << "Enter the elements of the rotated sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int index = searchInRotatedArray(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index+1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
