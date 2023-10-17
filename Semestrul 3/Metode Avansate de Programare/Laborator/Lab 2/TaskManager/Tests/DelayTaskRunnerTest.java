package Tests;

import Enum.ContainerStrategy;
import Model.MessageTask;
import Runners.DelayTaskRunner;
import Runners.PrinterTaskRunner;
import Runners.StrategyTaskRunner;

public class DelayTaskRunnerTest {

    public static void delayTaskRunnerTest(ContainerStrategy containerStrategy, MessageTask[] messageTasks) {
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(containerStrategy);
        DelayTaskRunner delayTaskRunner = new DelayTaskRunner(strategyTaskRunner);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(delayTaskRunner);
        printerTaskRunner.addTask(messageTasks[0]);
        printerTaskRunner.addTask(messageTasks[1]);
        printerTaskRunner.addTask(messageTasks[2]);
        printerTaskRunner.executeAll();
    }
}
