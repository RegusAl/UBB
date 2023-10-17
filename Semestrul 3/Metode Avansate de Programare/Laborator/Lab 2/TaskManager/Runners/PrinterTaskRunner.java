package Runners;

import java.time.LocalDateTime;

public class PrinterTaskRunner extends AbstractTaskRunner {
    public PrinterTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        System.out.println("Task executat la ora: " + LocalDateTime.now().getHour());
    }
}
