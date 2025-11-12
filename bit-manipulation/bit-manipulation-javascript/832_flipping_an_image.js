/**
 * Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
 *  To flip an image horizontally means that each row of the image is reversed.
 *  For example, flipping [1,1,0] horizontally results in [0,1,1].
 *  To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
 *  For example, inverting [0,1,1] results in [1,0,0].
 * @param {number[][]} image
 * @return {number[][]}
 */
 var flipAndInvertImage = function(image) {
    for (let i = 0; i < image.length; i++) {
        let [start, end] = [0, image[i].length - 1];
        for (let j = 0; j < image[i].length; j++) {
            while (start < end) {
                // flip image horizontally
                temp = image[i][start];
                image[i][start] = image[i][end];
                image[i][end] = temp;
                start++;
                end--;
            }
        }
    }


    for (let row = 0; row < image.length; row++) {
        for (let col = 0; col < image[row].length; col++) {
            if (image[row][col] === 0){
                image[row][col] = 1
            } else if(image[row][col] === 1) {
                image[row][col] = 0
            };
        }
    }

    for (let i = 0; i < image.length; i++) {
        const value = image[i];
        console.log(...value);
    }
};

function flip(image) {
    for (let row = 0; row < image.length; row++) {
        let [start, end] = [0, image[row].length - 1];
        console.log(start, end);
        for (let col = 0; col < image[row].length; col++) {
            while (start < end) {
                temp = image[row][start];
                image[row][start] = image[row][end];
                image[row][end] = temp;
                start++;
                end--;
            }
        }
    }
    return image[0];
}

console.log(flip([[1, 1, 0, 0]]));

// console.log(flipAndInvertImage(image = [[1,1,0],[1,0,1],[0,0,0]]));
// console.log(flipAndInvertImage(image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]));