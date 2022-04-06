import { fib } from './fib.js'
import Module from "./fibWASM.js"

const calcBtn = document.getElementById("calc-btn");
const fibN = document.getElementById("fib-n");

Module().then(function(mymod) {
  calcBtn.onclick = () => {
    let jsTime = jsRunner(parseInt(fibN.value));
    let cTime = cRunner(parseInt(fibN.value), mymod);
    addToTable([jsTime, cTime]);
    }
  }
)

const cRunner = (n, Module) => {
  const secondsC = new Date().getTime();
  Module._fib(n);
  const cTime = (new Date().getTime()) - secondsC;
  return cTime;
}

const jsRunner = (n) => {
  const secondsJS = new Date().getTime();
  console.log(fib(n))
  const javascripTime = (new Date().getTime()) - secondsJS;
  return javascripTime;
}

const addToTable = (resultArr) => {
  const table = document.getElementById("result-table");
  let row = table.insertRow(-1);
  let cell1 = row.insertCell(0);
  let cell2 = row.insertCell(1);
  let cell3 = row.insertCell(2);
  cell1.innerHTML = `${parseInt(fibN.value)}`;
  cell2.innerHTML = `${resultArr[0]} ms`;
  cell3.innerHTML = `${resultArr[1]} ms`;
}

