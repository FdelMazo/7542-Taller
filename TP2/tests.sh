./tp 3 1 1 input/zeroblk zeroblk3.out
./tp 8 1 1 input/pad pad8.out
./tp 4 1 1 input/oneblk oneblk4.out
./tp 4 1 1 input/largenum largenum4.out
./tp 4 1 1 input/alot alot4.out

diff zeroblk3.out output/zeroblk3.out
diff pad8.out output/pad8.out
diff oneblk4.out output/oneblk4.out
diff largenum4.out output/largenum4.out
diff alot4.out output/alot4.out