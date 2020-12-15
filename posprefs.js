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
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = +(readLine());
    let op = [];
    while(t--){
        let ans = [];
        let [n, k] = readLine().split(' ');
        n = + n;
        k = + k;
        for(let i=1; i<=n; i++){
            if(i%2 === 0)
                ans.push(-i);
            else 
                ans.push(i);
        }
        let pos = n/2;
        pos = Math.ceil(pos);
        if(pos > k){
            let i = n-1;
            let req = pos-k;
            while(req>0){
                if(ans[i] > 0){
                    ans[i] *= -1;
                    req--;
                }
                i--;
            }
        }
        if(pos < k){
            let i = n-1;
            let req = k-pos;
            while(req>0){
                if(ans[i] < 0){
                    ans[i] *= -1;
                    req--;
                }
                i--;
            }
        }
        op.push(ans.join(' '));
        // console.log(...ans);
    }
    console.log(op.join('\n'));
}
