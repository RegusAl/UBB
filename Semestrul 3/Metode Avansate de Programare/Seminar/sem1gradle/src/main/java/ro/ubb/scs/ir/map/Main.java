package ro.ubb.scs.ir.map;

import ro.ubb.scs.ir.map.domain.MassageTask;
import ro.ubb.scs.ir.map.domain.Task;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        //Task task = new Task("FF45", "Trimite un email!");
        //System.out.println(task);
        List<Task> list = new ArrayList<>();
        MassageTask message = new MassageTask("FF45", "Trimite un email!", "Salut!", "Sergiu",
                "Mama", LocalDateTime.now());
        list.add(message);
        message = new MassageTask("FF45", "Trimite un email!", "Trimite-mi bani!", "Sergiu",
                "Mama", LocalDateTime.now());
        list.add(message);
        message = new MassageTask("FF45", "Trimite un email!", "Nu-ti trimit nimic!", "Mama",
                "Sergiu", LocalDateTime.now());
        list.add(message);
        message = new MassageTask("FF45", "Trimite un email!", "Nu fi rea!", "Sergiu",
                "Mama", LocalDateTime.now());
        list.add(message);
        message = new MassageTask("FF45", "Trimite un email!", "Du-te la munca!", "Mama",
                "Sergiu", LocalDateTime.now());
        list.add(message);
        message.execute();
    }
}