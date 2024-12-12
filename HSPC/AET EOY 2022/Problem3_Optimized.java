import java.util.Arrays;

public class Problem3_Optimized {
    public static int[][] simulateWar(int[][] kingdom, int heirs, int numBattles) {
        int numRows = kingdom.length;
        int numCols = kingdom[0].length;
        boolean[][] attacked = new boolean[numRows][numCols];

        for (int battle = 0; battle < numBattles; battle++) {
            boolean[][] newlyAttacked = new boolean[numRows][numCols];
            int[][] updatedKingdom = new int[numRows][numCols];

            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numCols; col++) {
                    if (attacked[row][col]) {
                        int currentHeir = kingdom[row][col];
                        int leftNeighbor = kingdom[row][Math.min(col - 1, 0)];
                        int rightNeighbor = kingdom[row][Math.max(col + 1, numCols-1)];
                        int topNeighbor = kingdom[Math.max(row - 1, 0)][col];
                        int bottomNeighbor = kingdom[Math.min(row + 1, numRows-1)][col];

                        if ((currentHeir == (heirs - 1) && leftNeighbor == currentHeir) ||
                                (currentHeir != (heirs - 1) && leftNeighbor == currentHeir + 1)) {
                            updatedKingdom[row][col] = leftNeighbor;
                            newlyAttacked[row][(col - 1 + numCols) % numCols] = true;
                        } else if ((currentHeir == (heirs - 1) && rightNeighbor == 0) ||
                                (currentHeir != (heirs - 1) && rightNeighbor == currentHeir + 1)) {
                            updatedKingdom[row][col] = rightNeighbor;
                            newlyAttacked[row][(col + 1) % numCols] = true;
                        } else if ((currentHeir == (heirs - 1) && topNeighbor == 0) ||
                                (currentHeir != (heirs - 1) && topNeighbor == currentHeir + 1)) {
                            updatedKingdom[row][col] = topNeighbor;
                            newlyAttacked[(row - 1 + numRows) % numRows][col] = true;
                        } else if ((currentHeir == (heirs - 1) && bottomNeighbor == 0) ||
                                (currentHeir != (heirs - 1) && bottomNeighbor == currentHeir + 1)) {
                            updatedKingdom[row][col] = bottomNeighbor;
                            newlyAttacked[(row + 1) % numRows][col] = true;
                        } else {
                        updatedKingdom[row][col] = currentHeir;
                    }
                }
            }
        }
        printArray(kingdom);
        kingdom = updatedKingdom;
        attacked = newlyAttacked;
    }

        return kingdom;
}

    public static void main(String[] args) {
        //example test case
        //(You should try more of your own)

        /* Result after 1 battle:
         * 0 0 0
         * 0 0 1
         * 2 1 1
         *
         * Result after 2 battles:
         * 0 0 0
         * 2 0 0
         * 1 0 1
         */
        long startTime = System.currentTimeMillis();
        int[][] test1 = {{0,0,1}, {0,1,1}, {0,2,2}};
        test1 = simulateWar(test1, 3,   2);
        printArray(test1);

        int[][] test9 = {{2, 1}, {1,1}, {2,0}};
        test9 = simulateWar(test9, 3, 2);
        printArray(test9);
        /* Result after all 3 battles:
         * 3 3 3 0 0
         * 3 3 0 0 0
         * 3 0 0 0 0
         * 0 0 0 0 0
         * 0 0 0 0 0
         *
         * Brother 0 is very happy!
         */
        int[][] test2 = {{3,1,2,0,1}, {1,0,2,0,2}, {0,1,2,0,1}, {0,1,2,2,1}, {0,1,2,1,1}};
        test2 = simulateWar(test2, 4, 3);
        printArray(test2);

        long endTime = System.currentTimeMillis();
        long total = endTime - startTime;

        System.out.println(total);
    }
    //Measure-Command { java .\src\Problem1.java }
    //Measure-Command { java .\src\Problem3.java }
    // Measure-Command { java .\src\Problem2.java }
    public static void printArray(int[][] arr){
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}