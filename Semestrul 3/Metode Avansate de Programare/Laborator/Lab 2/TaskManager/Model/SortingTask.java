package Model;

import Enum.SortStrategy;

import java.util.Arrays;

public class SortingTask extends Task {

    private AbstractSorter abstractSorter;
    private final int[] numbers;
    private final SortStrategy sortStrategy;

//    public AbstractSorter getAbstractSorter() {
//        return abstractSorter;
//    }

    public SortingTask(String taskID, String descriere, int[] numbers, SortStrategy sortStrategy) {
        super(taskID, descriere);
        this.numbers = numbers;
        this.sortStrategy = sortStrategy;

        switch (sortStrategy) {
            case BUBBLESORT -> abstractSorter = new BubbleSort();
            case QUICKSORT -> abstractSorter = new QuickSort();
            default -> {
            }
        }
    }

    public void execute() {
        abstractSorter.sort(numbers);
        System.out.println(Arrays.toString(numbers) + "\n");
    }
}
