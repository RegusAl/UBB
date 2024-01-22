package org.comenzirestaurant.utils.observer;

import com.example.restaurante.utils.utils.Event;

public interface Observable<E extends Event> {
    void addObserver(Observer<E> observer);
    void removeObserver(Observer<E> observer);
    void notifyObservers(E event);
}
