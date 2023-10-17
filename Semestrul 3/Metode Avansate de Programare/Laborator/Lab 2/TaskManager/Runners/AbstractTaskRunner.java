package Runners;

import Model.Task;

public abstract class AbstractTaskRunner implements TaskRunner {
    private TaskRunner taskRunner;

    public AbstractTaskRunner(TaskRunner taskRunner) {
        this.taskRunner = taskRunner;
    }

    @Override
    public void executeOneTask() {
        this.taskRunner.executeOneTask();
    }

    @Override
    public void executeAll() {
        while (this.hasTask()) {
            this.executeOneTask();
        }
    }

    @Override
    public void addTask(Task t) {
        this.taskRunner.addTask(t);
    }

    @Override
    public boolean hasTask() {
        return this.taskRunner.hasTask();
    }
}
