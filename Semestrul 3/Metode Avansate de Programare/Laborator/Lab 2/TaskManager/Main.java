import Model.MessageTask;
import Model.QuickSort;
import Model.SortingTask;
import Enum.SortStrategy;
import Enum.ContainerStrategy;
import Model.Task;
import Runners.StrategyTaskRunner;
import Tests.MessageTaskTest;
import Tests.StrategyTaskRunnerTest;

import java.time.LocalDateTime;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello!");

        SortingTask task = new SortingTask("12", "Hello", new int[]{1, 4, 3}, SortStrategy.BUBBLESORT);
        System.out.println(task.getTaskID());
        System.out.println(task.getDescriere());

        int[] numbers = {4, 3, 2, 1};

//        BubbleSort bubbleSort = new BubbleSort();
//        bubbleSort.sort(numbers);

        QuickSort quickSort = new QuickSort();
        quickSort.sort(numbers);

        for (int i = 0; i < numbers.length; i++) {
            System.out.println(numbers[i]);
        }

        MessageTaskTest.testMessageTask();


//        StrategyTaskRunnerTest.strategyTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.getMessageTasks());

        StrategyTaskRunner runner = new StrategyTaskRunner(ContainerStrategy.LIFO);
        runner.addTask(new MessageTask("1", "salut", "aici este un mesaj", "A", "B", LocalDateTime.now()));
        runner.addTask(new MessageTask("2", "hello", "aici este un mesaj", "A", "B", LocalDateTime.now()));
        runner.addTask(new MessageTask("3", "hola", "aici este un mesaj", "A", "B", LocalDateTime.now()));
        runner.addTask(new MessageTask("4", "hallo", "aici este un mesaj", "A", "B", LocalDateTime.now()));
        runner.addTask(new MessageTask("5", "sal", "aici este un mesaj", "A", "B", LocalDateTime.now()));
        System.out.println(runner.hasTask());
        runner.executeAll();
        System.out.println(runner.hasTask());
    }

}
