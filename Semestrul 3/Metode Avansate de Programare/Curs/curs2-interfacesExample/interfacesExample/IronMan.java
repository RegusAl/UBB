package interfacesExample;

public class IronMan extends Character implements CanTalk, CanFly {

    @Override
    public void talk() {
        System.out.println("Hero talk");
    }

    @Override
    public void fly() {
        System.out.println("Hero fly");
    }

}