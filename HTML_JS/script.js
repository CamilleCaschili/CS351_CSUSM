

var c = 'a';
var f = 0.0;
var start = "Choose a number of";
var end = "jokes to display:";

function full(start, end) {
    return start + " " + end;
}

document.querySelector('.left').insertAdjacentHTML('afterbegin', `<p>${full(start, end)}</p>`);
do {
    console.log(c);
    c = String.fromCharCode(c.charCodeAt(0) + 1);
} while (c <= 'z');

while (f < 1.0) {
    console.log(f);
    f += 0.1;
}

function getJoke() {
    var jokeCount = document.getElementById('jokeCount').value;
    for (var i = 0; i < jokeCount; i++) {
        fetch('https://official-joke-api.appspot.com/jokes/programming/random')
            .then(response => response.json())
            .then(data => {
                var jokeDisplay = document.getElementById('jokeDisplay');
                var jokeDiv = document.createElement('div');
                jokeDiv.innerHTML = data[0].setup + '<br>' + data[0].punchline;
                jokeDiv.style.margin = '10px';
                jokeDiv.style.padding = '10px';
                jokeDiv.style.border = '1px solid #ccc';
                jokeDiv.style.boxShadow = '0 0 5px rgba(0, 0, 0, 0.1)';
                jokeDiv.style.borderRadius = '5px';
                jokeDisplay.appendChild(jokeDiv);
            });
    }
}

class Parent {
    constructor(name) {
        this.name = name;
    }

    sayHello() {
        console.log(`Hello, my name is ${this.name}`);
    }
}

class Child extends Parent {
    constructor(name, age) {
        super(name);
        this.age = age;
    }

    sayAge() {
        console.log(`I am ${this.age} years old`);
    }
}

let parent = new Parent("Christophe");
parent.sayHello();

let child = new Child("Camille", 24);
child.sayHello();
child.sayAge();