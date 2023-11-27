package map.toysocialnetwork.utils.events;

import map.toysocialnetwork.domain.User;

public class UserEvent implements Event {

    private ChangeEventType type;
    private User data, olddata;

    public UserEvent(ChangeEventType type, User data) {
        this.type = type;
        this.data = data;
    }

    public UserEvent(ChangeEventType type, User data, User olddata) {
        this.type = type;
        this.data = data;
        this.olddata = olddata;
    }

    public ChangeEventType getType() {
        return type;
    }

    public User getData() {
        return data;
    }

    public User getOlddata() {
        return olddata;
    }
}
