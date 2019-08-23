function checkDigit(c) {
    return c >= '0' && c <= '9';
}

function aggregateBonus(n, iter) {
    let ret = 1;
    if(iter === 'S'){
        iter = 1;
    } else if(iter === 'D') {
        iter = 2;
    } else {
        iter = 3;
    }
    while(iter--) {
        ret *= n;
    }
    return ret;
}

let beforeVal = 0;

function solution(dartResult) {
    var answer = 0;

    for(let i=0; i<dartResult.length;) {
        let k, iter, num;

        if(checkDigit(dartResult[i+1])) {
            num = parseInt(dartResult.substring(i, i+2), 10);
            k = i+2;
        } else {
        	num = parseInt(dartResult.substring(i, i+1), 10);
            k = i+1;
        }

        let bonus = dartResult[k++];
        let options = [];
        if(!checkDigit(dartResult[k])) {
            options.push(dartResult[k++]);
            if(!checkDigit(dartResult[k])) {
                options.push(dartResult[k++]);
            }
        }

        iter = aggregateBonus(num, bonus);

        options.forEach(option => {
            if(option === '*') {
                iter *= 2;
                beforeVal *= 2;
            }
            if(option === '#') {
                iter *= -1;
            }
        });
        answer += beforeVal;
        beforeVal = iter;
        i = k;
    }

    return answer + beforeVal;
}
console.log(solution('1D2S3T*'));
