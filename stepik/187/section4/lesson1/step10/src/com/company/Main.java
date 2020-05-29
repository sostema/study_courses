package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static String getCallerClassAndMethodName() {
        StackTraceElement[] stackTraceElements = new Throwable().getStackTrace();
        if (stackTraceElements.length <= 2){
            return null;
        }
        return stackTraceElements[2].getClassName() + "#" + stackTraceElements[2].getMethodName();
    }
}
