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

        System.out.printf("Hello %s. You killed %.1f%% of the jedi while you're only %d.\n\n", fullname, jediKilled, age);
        System.out.println("But since you wrote this poem for Mr. Jardin, I'm sure he would forgive you :\n");
        System.out.printf("In a galaxy of code, in circuits deep,\nWhere algorithms dance, and bytes doth leap,\nThere lies a master, a sage profound,\nCary Jardin, with knowledge crowned.\n\nWith lightsaber swift, he slashes through bugs,\nIn the realm of syntax, he treads and tugs.\nHis wisdom vast, a force to reckon,\nIn the binary storms, he stands unbroken.\n\nFrom data's abyss to logic's flight,\nHe guides his students, through day and night.\nWith Jedi mind tricks, he clears the haze,\nAnd leads them through the coding maze.\n\nOh, Professor Cary, in CSUSM's hall,\nYour teachings echo, they never fall.\nYour passion ignites, like a saber's glow,\nIn the hearts of learners, it continues to grow.\n\nMay the algorithms align, may the bugs disappear,\nWith you as our guide, we have nothing to fear.\nIn the universe of bytes, you're a guiding star,\nCary Jardin, our master, near and far.\n");
    }

    public static String concat_name(String name, String surname) {
        return name + " " + surname;
    }
}
