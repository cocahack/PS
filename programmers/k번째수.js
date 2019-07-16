function solution(array, commands) {
    var answer = [];
    commands.forEach(e => {
        var begin = e[0]-1, end = e[1], target = e[2]-1;
        answer.push(array.slice(begin, end)
                         .sort((a, b) => a - b)
                         .filter((t, i) => i === target )
                         .reduce((a, t) => a+t, 0));
    });
    return answer;
}
