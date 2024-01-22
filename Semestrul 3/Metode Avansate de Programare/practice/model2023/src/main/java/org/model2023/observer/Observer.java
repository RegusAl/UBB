package org.model2023.observer;


import com.example.model.utils.events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}