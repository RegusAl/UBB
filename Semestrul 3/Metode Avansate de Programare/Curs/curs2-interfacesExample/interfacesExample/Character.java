package interfacesExample;

public class Character implements CanFight{

    @Override
    public void fight() {
        System.out.println("Character fight");
    }

}