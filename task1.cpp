
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int linearSearch(vector<int>& arr, int n, int target) {
        for(int i=0;i<n;i++){
            if(arr[i]==target) return i;
        }
        return -1;
    }

    void inputIDs(vector<int>& arr, int n) {
        cout << "Enter student IDs:\n";

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void displayResult(int index) {
        if (index == -1) {
            cout << "Student ID not registered.\n";
        }
        else {
            cout << "Student ID found at index "
                 << index << endl;
        }
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

    obj.inputIDs(arr, n);

    cout << "Enter target student ID: ";
    cin >> target;

    if (!cin) {
        cout << "Invalid target ID.\n";
        return 0;
    }

    int result = obj.linearSearch(arr, n, target);

    obj.displayResult(result);

    int x;
    cin >> x;

    return 0;
}
