package Container;

import Model.Task;

public interface Container {
    Task remove();

    void add(Task task);

    int size();

    boolean isEmpty();
}
