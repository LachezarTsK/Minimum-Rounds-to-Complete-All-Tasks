
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
    static const int NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS = -1;
    
public:
    //C++20: int minimumRounds(span<const int> tasks) const ...
    int minimumRounds(const vector<int>& tasks) const {
        unordered_map<int, int> taskFrequency;
        for (int task : tasks) {
            ++taskFrequency[task];
        }

        int minRoundsToCompleteAllTasks = 0;
        for (const auto& [task, frequency] : taskFrequency) {
            if (frequency == 1) {
                return NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS;
            }
            minRoundsToCompleteAllTasks += ceil(static_cast<double>(frequency) / 3);
        }
        return minRoundsToCompleteAllTasks;
    }
};
