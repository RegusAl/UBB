package ro.ubb.scs.ir.map.domain;

public abstract class Task {
    private String taskID;
    private String desc;

    public Task(String taskID, String desc) {
        this.taskID = taskID;
        this.desc = desc;
    }

    public String getTaskID() {
        return taskID;
    }

    public String getDesc() {
        return desc;
    }

    /**
     * Seteaza o valoare taskId-ului
     * @param taskID ID-ul task-ului
     */
    public void setTaskID(String taskID) {
        this.taskID = taskID;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public abstract void execute();

    @Override
    public String toString() {
        return taskID + " " + desc;
    }
}
