package org.comenzirestaurant.utils.observer;

import com.example.restaurante.utils.utils.Event;

import java.util.HashSet;
import java.util.Set;

public abstract class ConcreteObservable<E extends Event> implements Observable<E> {
    private Set<Observer<E>> observers = new HashSet<>();

    @Override
    public void addObserver(Observer<E> observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer<E> observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(E event) {
        observers.forEach(observer -> observer.update(event));
    }
}