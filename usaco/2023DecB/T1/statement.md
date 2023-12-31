Farmer John's cows have quite the sweet tooth, and they especially enjoy eating candy canes! FJ has $N$ total cows, each with a certain initial height and he wants to feed them $M$ candy canes, each also of varying height ($1\le N,M≤2\cdot 10^5$).

FJ plans to feed the candy canes one by one to the cows, in the order they are given in the input. To feed a candy cane to his cows, he will hang the candy cane so that initially the candy cane is just touching the ground. The cows will then line up one by one, in the order given by the input, and go up to the candy cane, each eating up to their height (since they cannot reach any higher). The candy cane stays suspended in place where it is initially set up and is not lowered to the ground, even after cows eat the bottom of the candy cane. It is possible a cow may eat nothing during her turn, if the base of the candy cane is already above that cow's height. After every cow has had their turn, the cows grow in height by how many units of candy cane they ate, and Farmer John hangs the next candy cane and the cows repeat the process again (with cow 1 again being the first to start eating the next candy cane).



#### INPUT FORMAT (pipe stdin):

The first line contains $N$ and $M$.

The next line contains the initial heights of the $N$ cows, each in the range $[1,10^9]$.

The next line contains the heights of the $M$ candy canes, each in the range $[1,10^9]$.



#### OUTPUT FORMAT (pipe stdout):

The final heights of each of the $N$ cows on separate lines.

**Note that the large size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).**



#### SAMPLE INPUT:

```
3 2
3 2 5
6 1
```

#### SAMPLE OUTPUT:

```
7
2
7
```

The first candy cane is 66 units tall.

1. The first cow eats the portion of the first candy cane up to height 33, after which the remaining portion of the first candy cane occupies heights $[3,6]$.
2. The second cow is not tall enough to eat any of the remaining portion of the first candy cane.
3. The third cow eats two additional units of the first candy cane. The remaining portion of the first candy cane, occupying heights $[5,6]$, is not eaten.

Next, each cow grows by the amount she ate, so the heights of the cows become $[3+3,2+0,5+2]=[6,2,7]$.

The second candy cane is 11 unit tall, and the first cow eats all of it.



#### SCORING:



- Inputs 2-10: $N,M≤10^3$
- Inputs 11-14: No additional constraints.



Problem credits: Agastya Goel