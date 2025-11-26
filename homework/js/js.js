// 1
setTimeout(alert, 3000, "Hewwo");

// 2
function SayHi(name) {
    alert(`Hewwo ${name}!`);
}

let idk = prompt("Enter ur name?");

// 3
alert("Open the console!")
for (let i = 0; i < 10; i++) {
    setTimeout(() => console.log(i), i * 1000);
}

// 4
alert("Open the console!");
for (let i = 10; i >= 1; i--) {
    setTimeout(console.log, (10 - i) * 1000, i);
}
SetTimeout(console.log, 10000, "Start!")

// 5
let d = new Date();
console.log(`${d.getDate()} :: ${d.getMonth() + 1} :: ${d.getFullYear()}`);

// 6
function calculateAge(birthYear) {
    const now = new Date();
    const currentYear = now.getFullYear();
    return currentYear - birthYear;
}
let birthYear = Number(prompt("Enter your birth year:"));
let age = calculateAge(birthYear);
console.log(`You are ${age} years old.`);

// 7
let now = new Date();
let nextYear = new Date(now.getFullYear() + 1, 0, 1);
let diff = nextYear - now;
let daysLeft = Math.ceil(diff / (1000 * 60 * 60 * 24));
console.log(`There are ${daysLeft} days left until the New Year! 🎉`);

// 8
function getRandomNumber() {
    return Math.floor(Math.random() * 100) + 1;
}
console.log(`Your random number: ${getRandomNumber()}`);

// 9
function RollTheDice() {
    const roll = Math.ceil(Math.random() * 6);

    switch (roll) {
        case 1:
            console.log(`
+-------+
|       |
|   ●   |
|       |
+-------+
            `);
            break;
        case 2:
            console.log(`
+-------+
| ●     |
|       |
|     ● |
+-------+
            `);
            break;
        case 3:
            console.log(`
+-------+
| ●     |
|   ●   |
|     ● |
+-------+
            `);
            break;
        case 4:
            console.log(`
+-------+
| ●   ● |
|       |
| ●   ● |
+-------+
            `);
            break;
        case 5:
            console.log(`
+-------+
| ●   ● |
|   ●   |
| ●   ● |
+-------+
            `);
            break;
        case 6:
            console.log(`
+-------+
| ●   ● |
| ●   ● |
| ●   ● |
+-------+
            `);
            break;
    }
}

RollTheDice();

// 10
function ReturnMaxThree(n1, n2, n3) {
    return Math.max(n1, n2, n3);
}

let v1 = Number(prompt("Enter first numbah: "));
let v2 = Number(prompt("Enter second numbah: "));
let v3 = Number(prompt("Enter third numbah: "));

console.log(`The bigger one is ${ReturnMaxThree(v1, v2, v3)} `);

// 11
const targetDate = new Date(2025, 11, 31, 23, 59, 59);

function countdown() {
    const now = new Date();
    const diff = targetDate - now;

    if (diff <= 0) {
        console.log("Time's up! 🎉🔥");
        clearInterval(timer);
        return;
    }

    const days = Math.floor(diff / (1000 * 60 * 60 * 24));
    const hours = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((diff % (1000 * 60)) / 1000);

    console.log(`Time left: ${days} days ${hours} hours ${minutes} minutes ${seconds} seconds 😈🔥`);
}

const timer = setInterval(countdown, 1000);

// 12
function showTime() {
    const now = new Date();
    const hours = String(now.getHours()).padStart(2, '0');
    const minutes = String(now.getMinutes()).padStart(2, '0');
    const seconds = String(now.getSeconds()).padStart(2, '0');

    console.clear();
    console.log(`${hours}:${minutes}:${seconds}`);
}

setInterval(showTime, 1000);

// idk about colors so no 13
