package leetcode;

public class ReachingPoints {
    public static void main(String[] args) {
        ReachingPoints obj = new ReachingPoints();
        System.out.println(obj.reachingPoints(1, 1, 2, 2));
    }

    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (ty < tx) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }

        return (sx == tx && sy <= ty && (ty - sy) % sx == 0) || (sy == ty && sx < tx && (tx - sx) % sy == 0);
    }

}
