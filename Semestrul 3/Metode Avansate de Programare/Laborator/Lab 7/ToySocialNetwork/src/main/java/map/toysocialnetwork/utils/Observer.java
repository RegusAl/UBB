package map.toysocialnetwork.utils;


import map.toysocialnetwork.utils.events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}
