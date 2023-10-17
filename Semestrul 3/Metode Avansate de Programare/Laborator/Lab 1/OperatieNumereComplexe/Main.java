import Model.ComplexExpression;
import Model.ExpressionParser;
import Model.NumarComplex;

public class Main {

    public static void main(String[] args) {
        ExpressionParser parser = new ExpressionParser(args);
        ComplexExpression expr = parser.parse();
        NumarComplex result = expr.execute();
//        System.out.println(parser.parse().toString());
        System.out.println("Rezultatul expresiei este: " + result);
    }
}