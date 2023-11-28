package ro.ubb.scs.ir.map.domain;

public interface Container {
    Task remove();
    void add(Task task);
    int size();
    boolean isEmpty();
}



