package Tests;

import Model.MessageTask;
import Model.Task;
import Runners.StrategyTaskRunner;
import Runners.TaskRunner;
import Enum.ContainerStrategy;

public class StrategyTaskRunnerTest {

    public static void strategyTaskRunnerTest(ContainerStrategy containerStrategy, MessageTask[] messageTasks) {
        TaskRunner taskRunner = new StrategyTaskRunner(containerStrategy);
        taskRunner.addTask(messageTasks[0]);
        taskRunner.addTask(messageTasks[1]);
        taskRunner.addTask(messageTasks[2]);
        taskRunner.executeAll();
    }
}
