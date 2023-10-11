public class OperatieScadere extends ComplexExpression {
    public OperatieScadere(NumarComplex[] args) {
        super(Operation.SUBSTRACT, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.scadere(nr2);
    }
}
