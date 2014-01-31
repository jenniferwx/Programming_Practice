/**
* Given a rope with length n, how to cut the rope into m parts with length n[0], n[1], ..., n[m-1], in order to get 
* the maximal product of n[0]*n[1]* ... *n[m-1]? We have to cut once at least. 
* Additionally, the length of the whole length of the rope, as well as the length of each part, are in integer value.

* For example, if the length of the rope is 8, the maximal product of the part lengths is 18. In order to get the
* maximal product, the rope is cut into three parts with lengths 2, 3, and 3 respectively
*/

// Solution 1: DP: O(N^2) space O(N)
 public static int maxProductAfterCutting_solution1(int length) {
    if(length < 2) {
        return 0;
    }
    if(length == 2) {
        return 1;
    }
    if(length == 3) {
        return 2;
    }

    int[] products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    for(int i = 4; i <= length; ++i) {
        int max = 0;
        for(int j = 1; j <= i / 2; ++j) {
            int product = products[j] * products[i - j];
            if(max < product) {
                max = product;
            }
            products[i] = max;
        }
    }

    return products[length];
}

// Solution 2: O(1), space O(1)
 public static int maxProductAfterCutting_solution2(int length) {
    if(length < 2) {
        return 0;
    }
    if(length == 2) {
        return 1;
    }
    if(length == 3) {
        return 2;
    }

    int timesOf3 = length / 3;
    if((length - timesOf3 * 3) % 2 == 1) {
        timesOf3 -= 1;
    }

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int)(Math.pow(3, timesOf3)) * (int)(Math.pow(2, timesOf2));
}
