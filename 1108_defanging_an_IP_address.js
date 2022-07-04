/**
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 * A defanged IP address replaces every period "." with "[.]".
 * @param {string} address
 * @return {string}
 */
 var defangIPaddr = function(address) {
    let defanged = "";
    for (let i = 0; i < address.length; i++) {
        address[i] === "." ? defanged += "[.]" : defanged += address[i]
    }
    return defanged;
};
// test1 expected Output: "1[.]1[.]1[.]1"
let test1 = defangIPaddr("1.1.1.1");
console.log(test1);

// test2 expected Output: "255.100.50.0"
let test2 = defangIPaddr("255[.]100[.]50[.]0");
console.log(test2);
