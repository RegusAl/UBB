import Enum.ContainerStrategy;
import Enum.SortStrategy;
import Model.BubbleSort;
import Model.QuickSort;
import Model.SortingTask;
import Tests.DelayTaskRunnerTest;
import Tests.MessageTaskTest;
import Tests.PrinterTaskRunnerTest;
import Tests.StrategyTaskRunnerTest;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello!");

        SortingTask task = new SortingTask("12", "Hello", new int[]{1, 4, 3}, SortStrategy.BUBBLESORT);
        System.out.println(task.getTaskID());
        System.out.println(task.getDescriere());

        int[] n1 = {4, 3, 2, 1};

        BubbleSort bubbleSort = new BubbleSort();
        bubbleSort.sort(n1);

        for (int j : n1) {
            System.out.println(j);
        }

        int[] n2 = {4, 3, 2, 1};

        QuickSort quickSort = new QuickSort();
        quickSort.sort(n2);

        for (int j : n2) {
            System.out.println(j);
        }

        System.out.println("Test task-uri\n");
        MessageTaskTest.testMessageTask();
        System.out.println("\n");

        System.out.println("Test StrategyTaskRunner\n");
        System.out.println("LIFO");
        StrategyTaskRunnerTest.strategyTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");
        System.out.println("FIFO");
        StrategyTaskRunnerTest.strategyTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");

        System.out.println("Test PrinterTaskRunner\n");
        System.out.println("LIFO");
        PrinterTaskRunnerTest.printerTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");
        System.out.println("FIFO");
        PrinterTaskRunnerTest.printerTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");

        System.out.println("Test DelayTaskRunner\n");
        System.out.println("LIFO");
        DelayTaskRunnerTest.delayTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");
        System.out.println("FIFO");
        DelayTaskRunnerTest.delayTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.getMessageTasks());
        System.out.println("\n");


//        StrategyTaskRunner runner = new StrategyTaskRunner(ContainerStrategy.LIFO);
//        runner.addTask(new MessageTask("1", "salut", "aici este un mesaj", "A", "B", LocalDateTime.now()));
//        runner.addTask(new MessageTask("2", "hello", "aici este un mesaj", "A", "B", LocalDateTime.now()));
//        runner.addTask(new MessageTask("3", "hola", "aici este un mesaj", "A", "B", LocalDateTime.now()));
//        runner.addTask(new MessageTask("4", "hallo", "aici este un mesaj", "A", "B", LocalDateTime.now()));
//        runner.addTask(new MessageTask("5", "sal", "aici este un mesaj", "A", "B", LocalDateTime.now()));
//        System.out.println(runner.hasTask());
//        runner.executeAll();
//        System.out.println(runner.hasTask());
    }

}
