'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    rex();    
});

function readLine() {
    return inputString[currentLine++];
}

function rex() {
    let t = +(readLine());
    let op = [];
    while(t--){
        let [a,b] = readLine().split(' ');
        a = +a; b = +b;
        let c = a%b;
        op.push(c);
    }
    console.log(op.join('\n'));
}
