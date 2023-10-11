package Model;

import static Enum.Operation.SUBSTRACT;

public class OperatieScadere extends ComplexExpression {
    public OperatieScadere(NumarComplex[] args) {
        super(SUBSTRACT, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.scadere(nr2);
    }
}
