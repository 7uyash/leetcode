/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(num, power) {
    if (!power){
        return 1;
    }
    if (power < 0){
        num = 1/num;
        power = Math.abs(power);
    }
    if (power == 1){
        return num;
    }
    if (num == 1){
        return num;
    }
let tp = 1;
function pow(p, n){
    if (p*2 >= Math.floor(power/2)){
        tp = p;
        return n;
    }
    p = p*2;
    n = n*n;
    return pow(p, n);
}
let ans = pow(1, num);
for (tp; tp < Math.floor(power/2); tp++){
    ans = ans * num;
}
if(power%2 === 0){
    return ans*ans;
} else {
    return ans*ans*num;
}
};