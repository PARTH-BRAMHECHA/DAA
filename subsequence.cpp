#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& nums, int target, vector<int>& temp, int index, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(temp);
        return;
    }
    if (index >= nums.size() || target < 0) {
        return;
    }
    
    // Include the current element
    temp.push_back(nums[index]);
    findCombinations(nums, target - nums[index], temp, index, res);
    
    // Exclude the current element and move to the next
    temp.pop_back();
    findCombinations(nums, target, temp, index + 1, res);
}

int main() {
    cout << "Sum Subsequence" << endl;
    cout << "Input: Array Size(n), Array(nums), Target" << endl;
    cout << "Output: Combination List" << endl;

    for (int p = 1; p <= 3; p++) {
        cout << "Test case " << p << endl;

        int n;
        cin >> n;

        vector<int> candidates(n);
        for (int i = 0; i < n; i++) {
            cin >> candidates[i];
        }

        int target;
        cin >> target;

        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        findCombinations(candidates, target, temp, 0, res);

        // Printing result
        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (auto& comb : res) {
                cout << "[";
                for (int i = 0; i < comb.size(); i++) {
                    cout << comb[i];
                    if (i < comb.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "]";
            }
            cout << endl;
        }
    }
    return 0;
}
