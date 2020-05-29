package com.company;
import java.util.logging.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    private static void configureLogging() {
        Logger classA = Logger.getLogger("org.stepic.java.logging.ClassA");
        classA.setLevel(Level.ALL);
        Logger classB = Logger.getLogger("org.stepic.java.logging.ClassB");
        classB.setLevel(Level.WARNING);
        Logger other = Logger.getLogger("org.stepic.java");
        ConsoleHandler c = new ConsoleHandler();
        c.setLevel(Level.ALL);
        XMLFormatter a = new XMLFormatter();
        c.setFormatter(a);
        other.addHandler(c);
        other.setUseParentHandlers(false);
    }
}
