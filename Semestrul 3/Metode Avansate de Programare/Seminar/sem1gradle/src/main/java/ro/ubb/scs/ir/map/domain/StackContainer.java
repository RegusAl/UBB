package ro.ubb.scs.ir.map.domain;

import java.util.ArrayList;

public class StackContainer implements Container {
    private ArrayList<Task> list;

    public StackContainer(ArrayList<Task> list) {
        this.list = new ArrayList<>();
    }

    @Override
    public Task remove() {
        return null;
    }

    @Override
    public void add(Task task) {

    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }
}
