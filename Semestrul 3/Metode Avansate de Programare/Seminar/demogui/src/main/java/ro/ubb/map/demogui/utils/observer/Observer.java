package ro.ubb.map.demogui.utils.observer;


import ro.ubb.map.demogui.utils.events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}