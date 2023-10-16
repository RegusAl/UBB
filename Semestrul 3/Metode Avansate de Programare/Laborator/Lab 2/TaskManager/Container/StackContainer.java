package Container;

import Model.Task;

public class StackContainer extends AbstractContainer {

    public StackContainer() {
        tasks = new Task[10];
        size = 0;
    }

    @Override
    public Task remove() {
        if (!isEmpty()) {
            --this.size;
            return tasks[this.size];
        }
        return null;
    }
}
