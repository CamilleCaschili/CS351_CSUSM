fun main() {
    var name = "Anakin"
    var surname = "Skywalker"
    var age = 10
    var younglings = 7.6

    var fullname = concat_name(name, surname)

    for (i in 1..10) {
        println("Hello, $fullname! You are $age years old.")
        age += 1
    }

    while (age < 30) {
        println("Hello, $fullname! You are $age years old.")
        age += 1
    }

    do {
        println("Hello, $fullname! You are $age years old.")
        age += 1
    } while (age < 45)

    println("$fullname, you are now a master in Kotlin! You receive an A on this assignement!")
    println("Wait, you killed $younglings younglings!")
}

fun concat_name(name: String, surname: String): String {
    return (name + " " + surname)
}