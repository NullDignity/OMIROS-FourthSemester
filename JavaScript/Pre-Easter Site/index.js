"use strict";

function infoSubmitted() {
    /*
    .innerHTML <- Has Nested HTML
    .textContent <- Plain Text
    .style <- CSS
    .value <- Form
     */
    let fname = document.getElementById("name_input");
    let lname = document.getElementById("last_name_input");
    let para_elem = document.getElementById("para_id");
    para_elem.textContent = "Καλημέρα, " + fname.value + " " + lname.value;
}

function fruitTable() {
    let fruit_elem = document.getElementById("fruit_input");
    let table_elem = document.getElementById("fruit_table");
    table_elem.innerHTML += "<tr><td>" + fruit_elem.value + "</td></tr>";
}

function numberTable() {
    let table_elem = document.getElementById("number_table");
    for (let x = 1; x <= 100; x++) {
        table_elem.innerHTML += x + "<br>";
    }
}

function numberAddition() {
    let num_a = +document.getElementById("number_a").value;
    let num_b = +document.getElementById("number_b").value;
    let number_result = document.getElementById("number_result");
    number_result.value = num_a + num_b;
}

function numberSubtraction() {
    let num_a = +document.getElementById("number_a").value;
    let num_b = +document.getElementById("number_b").value;
    let number_result = document.getElementById("number_result");
    number_result.value = num_a - num_b;
}

function test() {
    let elem = document.getElementById("body_id");
    if (elem.style.backgroundColor === "violet") {
        elem.style.backgroundColor = "white";
    } else {
        elem.style.backgroundColor = "violet";
    }
}



/*
let name = "Anastasios";
for (let i = 0; i < name.length; i++) {
    document.write(name.charAt(i).toUpperCase() + "<br>");
}

function checkAge(age) {
    if (age >= 18) console.log(age + ": You can vote!");
    else console.log(age + ": You're too young to vote.");
}

alert("Good morning!");
document.write("Good morning!");
console.log("Good morning!");

let x = 18;
document.write("<br> X is " + x + "\u20AC.");
document.write("<br> I am under this!");

checkAge(20);
checkAge(18);
checkAge(17);

let name = "Anastasios";
let surname = "Lykos";
let fullName = name + " " + surname;
console.log(fullName);
console.log(fullName.length);
console.log(fullName.charAt(0));

let name = "Antonis";
let N = name.length;
document.write(name.charAt(2)); # 't';
*/

