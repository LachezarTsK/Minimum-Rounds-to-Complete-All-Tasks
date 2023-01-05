
import java.util.HashMap;
import java.util.Map;

public class Solution {

    private static final int NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS = -1;

    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> taskFrequency = new HashMap<>();
        for (int task : tasks) {
            taskFrequency.put(task, taskFrequency.getOrDefault(task, 0) + 1);
        }

        int minRoundsToCompleteAllTasks = 0;
        for (int currentFrequency : taskFrequency.values()) {
            if (currentFrequency == 1) {
                return NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS;
            }
            minRoundsToCompleteAllTasks += Math.ceil((double) currentFrequency / 3);
        }
        return minRoundsToCompleteAllTasks;
    }
}
