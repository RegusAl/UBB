import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.function.Predicate;

public class Main {

    // metoda generica
    public static <E> void printArie(List<E> l, Arie<E> f) {
        l.forEach(x -> System.out.println(f.compute(x)));
    }

    public static void main(String[] args) {

        Cerc cerc1 = new Cerc(2.0);
        Cerc cerc2 = new Cerc(3.0);

        List<Cerc> listaCercuri = Arrays.asList(cerc1, cerc2);

        Patrat patrat1 = new Patrat(1.0);
        Patrat patrat2 = new Patrat(2.0);

        List<Patrat> listaPatrate = Arrays.asList(patrat1, patrat2);

        // clasa interna
        Arie<Cerc> arieCerc = cerc -> Math.PI * cerc.getRaza() * cerc.getRaza();
        Arie<Patrat> ariePatrat = patrat -> patrat.getLatura() * patrat.getLatura();

//        System.out.println(arieCerc.compute(cerc1));
//        System.out.println(arieCerc.compute(cerc2));
//
//        System.out.println(ariePatrat.compute(patrat1));
//        System.out.println(ariePatrat.compute(patrat2));

        printArie(listaCercuri, arieCerc);
        printArie(listaPatrate, ariePatrat);

        List<String> stringList = Arrays.asList("ab", "abc", "aaabbbbcccc", "def", "xyz", "mnpq", "Al", "An", "nAnenuta", "Anel", "neluta");

        // afisare stringuri ce incep cu litera 'a'

        // sol1
        stringList.forEach(str -> {
            if (str.startsWith("a")) {
                System.out.println(str);
            }
        });

        // sol2
        stringList.stream()
                .filter(str -> str.startsWith("a"))
                .forEach(System.out::println);


        // tiparire prefixe pentru "Aneluta"
        List<String> stringList2 = new ArrayList<>(stringList);
        stringList2.stream()
                .filter("Aneluta"::startsWith)
                .forEach(System.out::println);

        System.out.println();

        // stergere celelalte

//        stringList2.removeIf(Predicate.not("Aneluta"::startsWith));

        Predicate<String> estePrefix = "Aneluta"::startsWith;
        stringList2.removeIf(estePrefix);
        stringList2.forEach(System.out::println);

        List<String> stringList4 = Arrays.asList("abc", "abd", "bcd", "bce", "cab");
        stringList4.stream()
                .filter(str -> {
                    System.out.println(str);
                    return str.startsWith("b");
                })
                .map(str -> {
                    System.out.println(str);
                    return str.toUpperCase();
                })
                .forEach(System.out::println);

    }
}