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
        let s = readLine();
        let mid = parseInt(s.length / 2);
        let a = s.substring(0, mid);
        let b = s.length % 2 ? s.substring(mid+1, s.length) : s.substring(mid, s.length);
        a = a.split("");
        b = b.split("");
        let dicta = {}, dictb = {};
        for(let i of a){
            if(dicta[i] == undefined)
                dicta[i] = 0;
            dicta[i]++;
        }
        for(let i of b){
            if(dictb[i] == undefined)
                dictb[i] = 0;
            dictb[i]++;
        }
        let flag = true;
        for(let i of "abcdefghijklmnopqrstuvwxyz"){
            if(dicta[i] !== dictb[i]){
                flag = false;
                break;
            }
        }
        if(flag)
            op.push("YES");
        else 
            op.push("NO");
    }
    console.log(op.join('\n'));
}
