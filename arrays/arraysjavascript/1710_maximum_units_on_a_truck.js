/**
 * You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes,
 * where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
 *     numberOfBoxesi is the number of boxes of type i.
 *     numberOfUnitsPerBoxi is the number of units in each box of the type i.
 * You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck.
 * You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
 * Return the maximum total number of units that can be put on the truck.
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
 var maximumUnits = function(boxTypes, truckSize) {
    let max_units = 0;
    let curr = 0;
    let box_no = 0;

    console.log(boxTypes.length);

    while (truckSize > 0 && boxTypes.length > 0 ) {
        //         find the box with the largest number of units
                for (let i = 0; i < boxTypes.length; i ++) {
                    if (boxTypes[i][1] > curr) {
                        box_no = i;
                        curr = Math.max(curr, boxTypes[i][1])
                    }
                }
        //         after finding the box, add the total number of units to the max units
                console.log(curr, boxTypes[box_no]);
                if (boxTypes[box_no][0] < truckSize) {
                    max_units += (boxTypes[box_no][0] * boxTypes[box_no][1]);
                    console.log(max_units);
                } else {
                    max_units += (truckSize * boxTypes[box_no][1]);
                }


        // //        reduce the number of boxes that are left to be loaded to the truck
                truckSize -= boxTypes[box_no][0];


        // //         remove the box from the list of boxTypes
                boxTypes.splice(box_no, 1);

        // //         set current maximum to 0 to start afresh
                curr = 0;
                // console.log(`truckSize: ${truckSize}, boxTypes:${boxTypes.length}`);
        }
            // return max_units

};
// test1
// let test1 = maximumUnits(boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4);
// console.log(test1);

// test2
let test2 = maximumUnits(boxTypes = [[1,3],[5,5],[2,5],[4,2],[4,1],[3,1],[2,2],[1,3],[2,5],[3,2]]
, truckSize = 35);
console.log(test2);
