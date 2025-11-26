alert("Time test begins now.");

function FindLonger(r1, r2)
{
    if (r1.length > r2.length) return 1;
    else if (r1.length < r2.length) return -1;
    else return 0;
}

s1 = prompt("Enter the first string: ")
s2 = prompt("Enter the second string: ")
alert(`You entered "${s1}" and "${s2}". The first row has ${s1.length} characters, and 2nd row has ${s2.length} characters, so... Well, ${FindLonger(s1, s2)}.`)

// example: s1 = Wyvern was killed sixteen days ago, do you seriously think your futile attempts to steal my fame would lead you somewhere?
// s2 = The king placed a bounty on your head, Sir Marigold, so you better find your way out of his lands before he finds you.
// output: 1

function Capatalata(string)
{
    return string.charAt(0).toUpperCase() + string.slice(1);
}

s3 = prompt("Enter a string to capitalize: ")
alert(Capatalata(s3))

// example: s3 = you makafaka
// output: You makafaka

function CountVowels(str) {
    let count = 0;
    for (let i = 0; i < str.length; i++) {
        let c = str.charAt(i).toLowerCase();
        if ("aeiouy".includes(c)) {
            count++;
        }
    }
    return count;
}

s4 = prompt("Enter a string > ")
alert(`This string has ${CountVowels(s4)} vowels.`)

// example: you would never wound an ice weilder with a young girl
// output: 21
