package com.company;

public class Main {

    public enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    }
    
    public static void main(String[] args) {
        Robot r = new Robot(0, 0, Direction.UP);
        moveRobot(r, 10, 5);
        System.out.println(r.x + " " + r.y);
    }

    static class Robot {
        int x;
        int y;
        Direction dir;

        public Robot (int x, int y, Direction dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        public Direction getDirection() {return dir;}

        public int getX() {return x;}

        public int getY() {return y;}

        public void turnLeft() {
            if      (dir == Direction.UP)    {dir = Direction.LEFT;}
            else if (dir == Direction.DOWN)  {dir = Direction.RIGHT;}
            else if (dir == Direction.LEFT)  {dir = Direction.DOWN;}
            else if (dir == Direction.RIGHT) {dir = Direction.UP;}
        }

        public void turnRight() {
            if      (dir == Direction.UP)    {dir = Direction.RIGHT;}
            else if (dir == Direction.DOWN)  {dir = Direction.LEFT;}
            else if (dir == Direction.LEFT)  {dir = Direction.UP;}
            else if (dir == Direction.RIGHT) {dir = Direction.DOWN;}
        }

        public void stepForward() {
            if (dir == Direction.UP)    {y++;}
            if (dir == Direction.DOWN)  {y--;}
            if (dir == Direction.LEFT)  {x--;}
            if (dir == Direction.RIGHT) {x++;}
        }
    }

    static void moveRobot(Robot robot, int toX, int toY) {
        int vectorX = toX - robot.getX();
        int vectorY = toY - robot.getY();
        if (vectorX < 0){
            while(robot.getDirection() != Direction.LEFT){
                robot.turnRight();
            }
        }
        else if (vectorX > 0){
            while(robot.getDirection() != Direction.RIGHT){
                robot.turnRight();
            }
        }
        for (int i = 0; i < vectorX; ++i){
            robot.stepForward();
        }
        if (vectorY < 0){
            while(robot.getDirection() != Direction.DOWN){
                robot.turnRight();
            }
        }
        else if (vectorY > 0){
            while(robot.getDirection() != Direction.UP){
                robot.turnRight();
            }
        }
        for (int i = 0; i < vectorY; ++i){
            robot.stepForward();
        }
    }
}
