package leetcode;

import java.util.PriorityQueue;

public class SorttheMatrixDiagonally {

    public int[][] diagonalSort(int[][] mat) {
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if (i != 0 && j != 0) {
                    continue;
                }
                PriorityQueue<Integer> queue = new PriorityQueue<>();
                int k = 0;
                while (i + k < mat.length && j + k < mat[i].length) {
                    queue.add(mat[i + k][j + k]);
                    k++;
                }

                k = 0;
                while (i + k < mat.length && j + k < mat[i].length) {
                    mat[i + k][j + k] = queue.remove();
                    k++;
                }
            }
        }
        return mat;
    }
}
