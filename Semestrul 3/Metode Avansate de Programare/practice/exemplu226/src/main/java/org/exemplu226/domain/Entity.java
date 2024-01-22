package org.exemplu226.domain;

public class Entity <ID>{
    private ID id;

    /**
     * Returns id of current entity
     * @return ID, id of current entity
     */
    public ID getId() {
        return id;
    }

    /**
     * Sets id of current entity
     * @param id, ID, new id
     */
    public void setId(ID id) {
        this.id = id;
    }
}
