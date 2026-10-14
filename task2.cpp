
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

    int binarySearch(vector<int>& arr, int low, int high, int target) {
        while(low<=high){
            int mid = low+ (high-low) /2;
            if(arr[mid]>target){
                high = mid-1;
            }
            else if (arr[mid]<target){
                low = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

public:

    void inputSortedIDs(vector<int>& arr, int n) {
        cout << "Enter registration IDs in sorted order:\n";

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    bool isSorted(vector<int>& arr, int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int search(vector<int>& arr, int target) {
        return binarySearch(arr, 0, (int)arr.size() - 1, target);
    }
};

int main() {
    int n, target;

    cout << "Enter number of students: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Invalid number of students.\n";
        return 0;
    }

    vector<int> arr(n);
    Solution obj;

    obj.inputSortedIDs(arr, n);

    if (!obj.isSorted(arr, n)) {
        cout << "Error: Array is not sorted.\n";
        return 0;
    }

    cout << "Enter registration ID to search: ";
    cin >> target;

    int result = obj.search(arr, target);

    if (result == -1) {
        cout << "Not found\n";
    }
    else {
        cout << "Found at index " << result << endl;
    }

    return 0;
}
