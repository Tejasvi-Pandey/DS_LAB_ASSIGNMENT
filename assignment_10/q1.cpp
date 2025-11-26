#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        if (s.find(nums[i]) != s.end()) {
            return true; 
        }
        s.insert(nums[i]);
    }

    return false; 
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    if (containsDuplicate(nums, n)) 
        cout << "True";
    else 
        cout << "False";

    return 0;
}
