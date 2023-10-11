public class OperatieAdaugare extends ComplexExpression {
    public OperatieAdaugare(NumarComplex[] args) {
        super(Operation.ADDITION, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.adunare(nr2);
    }
}
