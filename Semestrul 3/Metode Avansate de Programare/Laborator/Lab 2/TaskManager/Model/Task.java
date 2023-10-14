package Model;

public abstract class Task {
    private String taskID;
    private String descriere;

    public Task(String taskID, String descriere) {
        this.taskID = taskID;
        this.descriere = descriere;
    }

    public String getTaskID() {
        return taskID;
    }

    public void setTaskID(String taskID) {
        this.taskID = taskID;
    }

    public String getDescriere() {
        return descriere;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    public abstract void execute();

    @Override
    public String toString() {
        return "Model.Task{" + "taskID='" + taskID + '\'' + ", descriere='" + descriere + '\'' + '}';
    }
}
