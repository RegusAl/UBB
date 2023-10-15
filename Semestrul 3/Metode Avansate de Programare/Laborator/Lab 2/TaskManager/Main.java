import Model.BubbleSort;
import Model.MessageTask;
import Model.QuickSort;
import Model.SortingTask;
import Enum.SortStrategy;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello!");
//
//        BubbleSort bubbleSort = new BubbleSort();
//        int[] sortat = bubbleSort.sort(new int[]{3, 2, 1});
//        System.out.println(sortat);

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
    }

}
