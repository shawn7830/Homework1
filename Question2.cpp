#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNextGreaterElements(vector<int> &arr) {
    stack<int> s;
    vector<int> nge(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    int arrData[] = {4, 5, 2, 25};
    vector<int> arr(arrData, arrData + sizeof(arrData) / sizeof(arrData[0]));
    cout << "Next Greater Elements: " << endl;
    printNextGreaterElements(arr);

    return 0;
}
