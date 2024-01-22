package org.comenzirestaurant.exceptions;

public class ExistentEntityException extends RuntimeException {
    public ExistentEntityException() {
    }

    public ExistentEntityException(String message) {
        super(message);
    }

    public ExistentEntityException(String message, Throwable cause) {
        super(message, cause);
    }

    public ExistentEntityException(Throwable cause) {
        super(cause);
    }

    public ExistentEntityException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
