public class Triangle {
    private int side_1, side_2, side_3;

    // Constructors
    public Triangle() {
        setSides(1, 1, 1);
    }

    public Triangle(int side_1) {
        setSides(side_1, 1, 1);
    }

    public Triangle(int side_1, int side_2) {
        setSides(side_1, side_2, 1);
    }

    public Triangle(int side_1, int side_2, int side_3) {
        setSides(side_1, side_2, side_3);
    }

    // Setters
    public void setSide_1(int side_1) {
        this.side_1 = side_1;
    }

    public void setSide_2(int side_2) {
        this.side_2 = side_2;
    }

    public void setSide_3(int side_3) {
        this.side_3 = side_3;
    }

    public void setSides(int side_1, int side_2, int side_3) {
        this.side_1 = side_1;
        this.side_2 = side_2;
        this.side_3 = side_3;
    }

    // Getters
    public int getSide_1() {
        return this.side_1;
    }

    public int getSide_2() {
        return this.side_2;
    }

    public int getSide_3() {
        return this.side_3;
    }

    // Functions
    public void printSides() {
        System.out.println("Η πρώτη πλευρά έχει μήκος:\t" + getSide_1());
        System.out.println("Η δεύτερη πλευρά έχει μήκος:\t" + getSide_2());
        System.out.println("Η τρίτη πλευρά έχει μήκος:\t" + getSide_3() + "\n");
    }

}
