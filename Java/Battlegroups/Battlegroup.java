import java.util.Random;

public class Battlegroup {

    private static final int TOP_SPEED = 100, MAX_FIREPOWER = 1000, MAX_NUMBER_OF_STARSHIPS = 10;
    private static int numOfBattleGroups = 0;
    private static Random random = new Random();
    private String name;
    private Starship ships[];
    private int speed, firePower;

    public Battlegroup(String name, int resources) {
        int spd=0, firp=0;
        this.name = name;

        ships = new Starship[resources/(random.nextInt(MAX_NUMBER_OF_STARSHIPS))];

        for (int i=0; i < ships.length; i++) {
            ships[i] = new Starship(getName() + "-" + i, random.nextInt(TOP_SPEED), random.nextInt(MAX_FIREPOWER));
            spd += ships[i].getSpeed();
            firp += ships[i].getFirePower();
        }

        this.speed = (int)spd/ships.length;
        this.firePower = firp;
        numOfBattleGroups++;
    }

    public String getName() {
        return this.name;
    }

    public int getSpeed() {
        return this.speed;
    }

    public int getFirePower() {
        return this.firePower;
    }

    public void printGroupDetails() {
        System.out.println("The name of the Battlegroup is: " + getName() + "\nits speed is: " + getSpeed() + "\nand its firepower is: " + getFirePower());
        System.out.println("And it contains the following starships:\n");
        for (int i=0; i < ships.length; i++) {
            ships[i].printShipDetails();
        }
        System.out.println("\n---------------------------\n\n");
    }

}
