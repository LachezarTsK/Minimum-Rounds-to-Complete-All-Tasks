
/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function (tasks) {
    const NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS = -1;
    const taskFrequency = new Map();// Map<number, number>
    for (let task of tasks) {
        taskFrequency.set(task, (taskFrequency.get(task) ? taskFrequency.get(task) : 0) + 1);
    }

    let minRoundsToCompleteAllTasks = 0;
    for (let currentFrequency of taskFrequency.values()) {
        if (currentFrequency === 1) {
            return NOT_POSSIBLE_TO_COMPLETE_ALL_TASKS;
        }
        minRoundsToCompleteAllTasks += Math.ceil(currentFrequency / 3);
    }
    return minRoundsToCompleteAllTasks;
};
