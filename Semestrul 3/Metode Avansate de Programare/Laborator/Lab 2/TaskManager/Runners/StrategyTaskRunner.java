package Runners;


import Container.Container;
import Enum.ContainerStrategy;
import Factory.TaskContainerFactory;
import Model.Task;

public class StrategyTaskRunner implements TaskRunner {

    private Container container;

    public StrategyTaskRunner(ContainerStrategy containerStrategy) {
        this.container = TaskContainerFactory.getInstance().createContainer(containerStrategy);
    }

    @Override
    public void executeOneTask() {
        container.remove().execute();
    }

    @Override
    public void executeAll() {
        while (hasTask()) {
            executeOneTask();
        }
    }

    @Override
    public void addTask(Task t) {
        container.add(t);
    }

    @Override
    public boolean hasTask() {
        return !container.isEmpty();
    }
}
