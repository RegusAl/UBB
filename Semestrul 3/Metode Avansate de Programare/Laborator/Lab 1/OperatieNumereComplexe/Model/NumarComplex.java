package Model;

public class NumarComplex {
    private double re; // numar real
    private double im; // numar imaginar

    public NumarComplex(double re, double im) {
        this.re = re;
        this.im = im;
    }

    // adunare
    public NumarComplex adunare(NumarComplex other) {
        return new NumarComplex(this.re + other.re, this.im + other.im);
    }

    // scadere
    public NumarComplex scadere(NumarComplex other) {
        return new NumarComplex(this.re - other.re, this.im - other.im);
    }

    // inmultire
    public NumarComplex inmultire(NumarComplex other) {
        double re = this.re * other.re - this.im * other.im;
        double im = this.re * other.im + this.im * other.re;
        return new NumarComplex(re, im);
    }

    // impartire
    public NumarComplex impartire(NumarComplex other) {
        double re = (this.re * other.re + this.im * other.im) / (other.re * other.re + other.im * other.im);
        double im = (other.re * this.im - this.re * other.re / (other.re * other.re + other.im * other.im));
        return new NumarComplex(re, im);
    }

    @Override
    public String toString() {
        return re + " + " + im + "*i";
    }
}
