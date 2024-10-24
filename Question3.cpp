#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printFirstNegativeInteger(vector<int> &arr, int k) {
    deque<int> dq;
    for (int i = 0; i < arr.size(); i++) {
        
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        if (arr[i] < 0) {
            dq.push_back(i);
        }
        
        if (i >= k - 1) {
            if (!dq.empty()) {
                cout << arr[dq.front()] << " ";
            } else {
                cout << 0 << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int arrData[] = {-8, 2, 3, -6, 10};
    vector<int> arr(arrData, arrData + sizeof(arrData) / sizeof(arrData[0]));
    int k = 2;
    cout << "First Negative Integer for each window of size " << k << ": " << endl;
    printFirstNegativeInteger(arr, k);

    return 0;
}

