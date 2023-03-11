var unsorted_number = [15,25,1,3,4,87,2,34,6,66,12];

for (let a = 0; a < unsorted_number.length; a++) {
    for (let xyz = 0; xyz < unsorted_number.length; xyz++) {
        if (unsorted_number[xyz]> unsorted_number[xyz+1]) {
            let idk = unsorted_number[xyz+1]
            unsorted_number[xyz+1] = unsorted_number[xyz]
            unsorted_number[xyz] = idk
        }
        
    }

}
console.log(unsorted_number)