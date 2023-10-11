public class OperatieInmultire extends ComplexExpression {
    public OperatieInmultire(NumarComplex[] args) {
        super(Operation.MULTIPLY, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.inmultire(nr2);
    }
}
