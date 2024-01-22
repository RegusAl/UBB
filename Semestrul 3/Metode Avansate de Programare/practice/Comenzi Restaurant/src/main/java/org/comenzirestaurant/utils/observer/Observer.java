package org.comenzirestaurant.utils.observer;

import com.example.restaurante.utils.utils.Event;

public interface Observer<E extends Event> {
    void update(E event);
}

