public class Starship {

    private String name;
    private int speed, firePower;

    public Starship(String name, int speed, int firePower) {
        this.name = name;
        this.speed = speed;
        this.firePower = firePower;
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

    public void setName(String new_name) {
        this.name = new_name;
    }

    public void setSpeed(int new_speed) {
        this.speed = new_speed;
    }

    public void setFirePower(int new_firePower) {
        this.firePower = new_firePower;
    }

    public void printShipDetails() {
        System.out.println("The name of this Starship is: " + getName() + ", \nits speed is: " + getSpeed() + ", \nand its firepower is: " + getFirePower() + ".\n");
    }

}
