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
    console.log(p, n);
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
console.log(ans);
if(power%2 === 0){
    console.log('even');
    console.log(ans*ans);
    return ans*ans;
} else {
    console.log(ans*ans*num);
    return ans*ans*num;
}
};