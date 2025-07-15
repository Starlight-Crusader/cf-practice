import java.util.List;
import java.util.ArrayList;
import java.util.EnumMap;
import java.util.Scanner;

public class Solution {
    private enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    }

    public static void main(String[] args) {
        EnumMap<Direction, int[]> directionVectors = new EnumMap<>(Direction.class);
        directionVectors.put(Direction.UP, new int[] { -1, 0 });
        directionVectors.put(Direction.DOWN, new int[] { 1, 0 });
        directionVectors.put(Direction.LEFT, new int[] { 0, -1 });
        directionVectors.put(Direction.RIGHT, new int[] { 0, 1 });

        EnumMap<Direction, Direction> directionOpposites = new EnumMap<>(Direction.class);
        directionOpposites.put(Direction.UP, Direction.DOWN);
        directionOpposites.put(Direction.DOWN, Direction.UP);
        directionOpposites.put(Direction.LEFT, Direction.RIGHT);
        directionOpposites.put(Direction.RIGHT, Direction.LEFT);

        EnumMap<Direction, Character> direction2Character = new EnumMap<>(Direction.class);
        direction2Character.put(Direction.UP, 'U');
        direction2Character.put(Direction.DOWN, 'D');
        direction2Character.put(Direction.LEFT, 'L');
        direction2Character.put(Direction.RIGHT, 'R');

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();

        boolean[][] field = new boolean[n][m];
        int startX = -1, startY = -1;
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();

            for (int j = 0; j < m; j++) {
                if (line.charAt(j) == '.') {
                    field[i][j] = false;
                } else if (line.charAt(j) == '*') {
                    field[i][j] = true;
                } else {
                    startX = j;
                    startY = i;
                    field[i][j] = true;
                }
            }
        }

        List<Character> path = new ArrayList<>();
        int x = startX, y = startY;
        Direction lastStepDirOpposite = null;
        do {
            for (Direction dir : directionVectors.keySet()) {
                int dY = y + directionVectors.get(dir)[0], dX = x + directionVectors.get(dir)[1];
                if ((dY >= 0 && dY < n) && (dX >= 0 && dX < m)) {
                    if (field[dY][dX] && dir != lastStepDirOpposite) {
                        path.add(direction2Character.get(dir));
                        x = dX;
                        y = dY;
                        lastStepDirOpposite = directionOpposites.get(dir);
                        break;
                    }
                }
            }
        } while (x != startX || y != startY);

        for (Character c : path) {
            System.out.print(c);
        }
    }
}