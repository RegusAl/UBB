public class ExpressionFactory {
    private static ExpressionFactory instance;

    private ExpressionFactory() {}

    public static ExpressionFactory getInstance() {
        if(instance == null) {
            instance=  new ExpressionFactory();
        }
        return instance;
    }

    public ComplexExpression createExpression(Operation operation, NumarComplex[] args) {
        switch (operation) {
            case ADDITION -> {
                return new OperatieAdaugare(args);
            }
            case SUBSTRACT -> {
                return new OperatieScadere(args);
            }
            case DIVIDE -> {
                return new OperatieImpartire(args);
            }
            case MULTIPLY -> {
                return new OperatieInmultire(args);
            }
            default -> {
                return null;
            }
        }
    }
}
