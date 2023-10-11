public class OperatieImpartire extends ComplexExpression {
    public OperatieImpartire(NumarComplex[] args) {
        super(Operation.DIVIDE, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.impartire(nr2);
    }
}
