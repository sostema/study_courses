package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public interface RobotConnection extends AutoCloseable {
        void moveRobotTo(int x, int y);
        @Override
        void close();
    }

    public interface RobotConnectionManager {
        RobotConnection getConnection();
    }

    public class RobotConnectionException extends RuntimeException {

        public RobotConnectionException(String message) {
            super(message);

        }

        public RobotConnectionException(String message, Throwable cause) {
            super(message, cause);
        }
    }

    public static void moveRobot(RobotConnectionManager robotConnectionManager, int toX, int toY) {
        for (int i = 0; i < 3; ++i){
            boolean success = false;
            try (RobotConnection connection = robotConnectionManager.getConnection()){
                connection.moveRobotTo(toX, toY);
                success = true;
                i = 3;
            }
            catch (RobotConnectionException e){
                if (i >= 2 && !success){
                    throw e;
                }
            }
            catch (Exception e){
                throw e;
            }
        }
    }
}
