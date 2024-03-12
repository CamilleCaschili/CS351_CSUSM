public class hello {
    public static void main(String[] args) {
        int age = 10;
        String name = "Anakin";
        String surname = "Skywalker";
        Double jediKilled = 95.8;

        String fullname = concat_name(name, surname);

        for (int i = 0; i < 10; i++)
            age++;

        while (age < 30)
            age++;

        do
            age++;
        while (age < 50);

        System.out.println("Hello " + fullname);
        System.out.println("You killed " + jediKilled + "% of the jedi");
        System.out.println("While you're only " + age);
    }

    public static String concat_name(String name, String surname) {
        return name + " " + surname;
    }
}
