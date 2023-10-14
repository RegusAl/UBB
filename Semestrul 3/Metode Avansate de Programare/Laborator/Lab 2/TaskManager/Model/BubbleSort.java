package Model;

public class BubbleSort extends AbstractSorter {
    @Override
    public void sort(int[] numbers) {
        int nr = numbers.length;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nr - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int aux = numbers[j];
                    numbers[j] = numbers[i];
                    numbers[i] = aux;
                }
            }
        }
    }
}
