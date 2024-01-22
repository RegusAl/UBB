package org.comenzirestaurant.exceptions;

public class InexistentEntityException extends RuntimeException {
    public InexistentEntityException() {
    }

    public InexistentEntityException(String message) {
        super(message);
    }

    public InexistentEntityException(String message, Throwable cause) {
        super(message, cause);
    }

    public InexistentEntityException(Throwable cause) {
        super(cause);
    }

    public InexistentEntityException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}