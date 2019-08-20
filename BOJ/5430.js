let fs = require('fs');
let inputs = fs.readFileSync('/dev/stdin').toString().split('\n');
let idx = 0;

let t = parseInt(inputs[idx++]);

while (t--) {
  const commands = inputs[idx++], len = parseInt(inputs[idx++]);
  const arr = JSON.parse(inputs[idx++]);
  solve(commands, arr);
}

function solve (commands, arr) {
  let reverse = false;
  for (const c of commands) {
    if(c === 'R') {
      reverse ^= 1;
    } else {
      if (arr.length == 0) {
        console.log('error');
        return;
      }
      if (reverse) {
        arr.pop();
      } else {
        arr.shift();
      }
    }
  }
  if(reverse) arr.reverse();
  console.log(JSON.stringify(arr));
}

