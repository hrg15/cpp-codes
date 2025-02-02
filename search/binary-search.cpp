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


int binarySearch(int a[],int low, int high, int key ){
    int mid;
    if(low <= high ){
        mid = (low + high )/2;
        if(a[mid] == key) return mid;
        if(a[mid] < key ) return binarySearch(a, mid+1, high, key);
        if(a[mid] > key ) return binarySearch(a, low, mid-1, key);
    }
    return -1;
}

int deleteElement (int a[],int n, int key){
    int res = binarySearch(a,0 , n-1 , key );
    if(res == -1) cout<< "There isn't element to delete!";
    for(int i = res; i<=n-2 ; i++){
        a[i] = a[i+1];
    }
    return n-1;
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

    int a[] = {8 , 9 , 12, 25,85, 102};
    int h = sizeof(a)/sizeof(a[0]);
    int key = 85;
    int res = binarySearch(a,0 , h-1 , key ); 
    if(res == -1)
        cout<< "Not found!";
    else
        cout<<"Found: "<< res << endl;
        
    n=deleteElement(a,h ,12);
    
    for(int i=0; i<n ; i++)
        cout<<a[i]<< " ";

    int index = searchInRotatedArray(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index+1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
