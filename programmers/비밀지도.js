function solution(n, arr1, arr2) {
    var answer = [];
    var cross = arr1.map((low, i) => low | arr2[i]);
    for(let i=0; i<n; ++i) {
        let j=0, str = "";
        while(cross[i]) {
            if(cross[i] % 2 != 0) {
                str += "#";
            } else {
                str += " ";
            }
            ++j;
            cross[i] = parseInt(cross[i] / 2, 10);
        }
        while(j !== n) {
            str += " ";
            ++j;
        }
        answer.push(str.split('').reverse().join(''));
    }
    return answer;
}

