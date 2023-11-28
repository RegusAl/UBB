package ro.ubb.scs.ir.map.domain;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MassageTask extends Task {
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;
    public static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy hh:mm");

    public MassageTask(String taskID, String desc, String mesaj, String from, String to, LocalDateTime date) {
        super(taskID, desc);
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    public String toString(){
        return super.toString() + " " + mesaj + " " + from + " " + to + " "+ formatter.format(date);
    }
    @Override
    public void execute() {
        System.out.println("Task-ul: " + this.toString() + " executat cu succes!" +
                "La data de " + formatter.format(LocalDateTime.now()));
    }
}
