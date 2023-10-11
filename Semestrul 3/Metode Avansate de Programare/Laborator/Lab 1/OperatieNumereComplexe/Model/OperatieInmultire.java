package Model;

import static Enum.Operation.MULTIPLY;

public class OperatieInmultire extends ComplexExpression {
    public OperatieInmultire(NumarComplex[] args) {
        super(MULTIPLY, args);
    }

    public NumarComplex executeOneOperation(NumarComplex nr1, NumarComplex nr2) {
        return nr1.inmultire(nr2);
    }
}
