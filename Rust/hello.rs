fn add_one(x: i32) -> i32 {
    x + 1
}

mod hello {
    pub fn quiz() {
        println!("You have ton answer to this question: What's the best programming language between those three ?\nRust, C or Cobol\nThere is one and only one correct answer.");
    }
}

fn main() {
    let mut x = 5;
    let y = 5.5;
    let mut v = vec![1, 2, 3];

    let first_name = "Camille";
    let last_name = "Caschili";
    let full_name = first_name.to_string() + " " + last_name;

    println!("Hello, {}!", full_name);

    while x < 10 {
        x = add_one(x);
    }

    loop {
        x = add_one(x);
        if x == 15 {
            break;
        }
    }

    for _ in 0..10 {
        x = add_one(x);
    }


    while let Some(x) = v.pop() {
        println!("{}", x);
    }

    println!("{} {}", x, y);

    hello::quiz();
}