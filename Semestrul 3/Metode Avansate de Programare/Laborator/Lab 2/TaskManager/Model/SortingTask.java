package Model;
import Enum.SortStrategy;

public class SortingTask extends Task {

    private AbstractSorter abstractSorter;
    private int[] numbers;
    private SortStrategy sortStrategy;

    public SortingTask(String taskID, String descriere, AbstractSorter abstractSorter, int[] numbers, SortStrategy sortStrategy) {
        super(taskID, descriere);
        this.numbers = numbers;
        this.sortStrategy = sortStrategy;

        switch (sortStrategy) {
            case BUBBLESORT -> abstractSorter = new BubbleSort();
//            case QUICKSORT -> abstractSorter = new QuickSort();
        }
    }

    public void execute() {
        abstractSorter.sort(numbers);
    }
}
