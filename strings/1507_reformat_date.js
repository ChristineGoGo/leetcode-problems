/**
 * Given a date string in the form Day Month Year, where:
 *  Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
 * Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
 * Year is in the range [1900, 2100].
 * Convert the date string to the format YYYY-MM-DD, where:
 *   YYYY denotes the 4 digit year.
 *   MM denotes the 2 digit month.
 *   DD denotes the 2 digit day.
 * @param {string} date
 * @return {string}
 */
 var reformatDate = function(date) {
    const months = {
        Jan: '01',
        Feb: '02',
        Mar: '03',
        Apr: '04',
        May: '05',
        Jun: '06',
        Jul: '07',
        Aug: '08',
        Sep: '09',
        Oct: '10',
        Nov: '11',
        Dec: '12',
    };

    // console.log(months['Jan']);

    const unformated_date = date.split(" ");
    let formated_date = [];
    const length = unformated_date.length - 1;
    // console.log(unformated_date[length]);

    for (let i = length; i >= 0; i--) {
        let curr = parseInt(unformated_date[i], 10);
        // console.log(curr);
        if (isNaN(curr) === true) {
            formated_date.push(months[unformated_date[i]]);
        } else {
            (curr < 10) ? formated_date.push("0" + curr.toString()) : formated_date.push(curr);
        }
    }

    return formated_date.join("-");
};