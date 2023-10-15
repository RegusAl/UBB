package Container;

import Model.Task;

public class QueueContainer extends AbstractContainer {

    public QueueContainer() {
        tasks = new Task[10];
        size = 0;
    }

    @Override
    public Task remove() {
        if (isEmpty()) {
            Task task = tasks[0];
            for (int i = 0; i < tasks.length; i++) {
                tasks[i] = tasks[i + 1];
            }
            size--;
            return task;
        }
        return null;
    }
}
