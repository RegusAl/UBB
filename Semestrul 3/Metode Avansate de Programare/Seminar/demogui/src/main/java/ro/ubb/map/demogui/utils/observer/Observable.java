package ro.ubb.map.demogui.utils.observer;


import ro.ubb.map.demogui.utils.events.Event;

public interface Observable<E extends Event> {
    void addObserver(Observer<E> e);
    void removeObserver(Observer<E> e);
    void notifyObservers(E t);
}
