function solution(n, s) {
    var answer = []
    if(n > s) return [-1];
    
    var idx = n;
    while(idx){
        var q = Math.floor(s/idx);
        answer.push(q);
        s -= q;
        idx--;
    }
    
    answer.sort();
    return answer;
}
