function main() {
  let c = 1;
  let k = 0;
  do {
    console.log(`loop begin: k = ${k}', c = ${c}`);
    console.log(`c++ 先判断，再加1`);
    switch (c++) {
      case 1:
        console.log('case A: c = ', c);
        k++;
        console.log("'k++;' Then k = ", k);
        break;
      case 2:
        console.log('case B: c = ', c);
        k--;
        console.log("'k--;' Then k = ", k);
      case 3:
        console.log('case C: c = ', c);
        k += 2;
        console.log("'k += 2;' Then k = ", k);
        break;
      case 4:
        console.log('case D: c = ', c);
        k %= 2;
        console.log("'k %= 2;' Then k = ", k);
        continue;
      case 5:
        console.log('case E: c = ', c);
        k *= 10;
        console.log("'k *= 10;' Then k = ", k);
        break;
      default:
        console.log('default: c = ', c);
        k /= 3;
        console.log("'k /= 3;' Then k = ", k);
        break;
    }

    k++;

    console.log('loop end: k = ', k);
  } while (c < 7);

  console.log(k);
}

function loop() {
  let i;
  let str = '';
  for (i = 1; i <= 5; i++) {
    console.log(`loop begin: i = ${i}`);
    switch (i % 2) {
      case 0:
        i++;
        str += '#';
        break;
      case 1:
        i += 2;
        str += '#';
      default:
        str += '\n';
    }
  }

  console.log(str);
}
