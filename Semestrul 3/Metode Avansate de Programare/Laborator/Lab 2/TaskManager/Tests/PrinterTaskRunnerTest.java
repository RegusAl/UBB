package Tests;

import Model.MessageTask;
import Runners.PrinterTaskRunner;
import Runners.StrategyTaskRunner;
import Enum.ContainerStrategy;

public class PrinterTaskRunnerTest {

    public static void printerTaskRunnerTest(ContainerStrategy containerStrategy, MessageTask[] messageTasks) {
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(containerStrategy);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.addTask(messageTasks[0]);
        printerTaskRunner.addTask(messageTasks[1]);
        printerTaskRunner.addTask(messageTasks[2]);
        printerTaskRunner.executeAll();
    }
}
