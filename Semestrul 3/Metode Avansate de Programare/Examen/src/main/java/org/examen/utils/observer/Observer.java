package org.examen.utils.observer;


import com.example.model.utils.events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}