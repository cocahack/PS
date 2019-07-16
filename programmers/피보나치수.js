var MOD = 1234567;
function solution(n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    var first = 0, second = 0, third = 1;
    
    for(var i = 2; i <= n; ++i){
        first = second, second = third;
        third = ((first % MOD) + (second % MOD) ) % MOD;
    }
    
    return third;
}
