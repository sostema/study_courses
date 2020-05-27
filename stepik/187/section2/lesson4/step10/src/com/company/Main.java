package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }
    private String printTextPerRole(String[] roles, String[] textLines) {
        StringBuilder result = new StringBuilder();
        for (String role : roles) {
            result.append(role).append(":\n");
            for (int k = 0; k < textLines.length; ++k) {
                String textLine = textLines[k];
                if (textLine.indexOf(role+":") == 0) {
                    result.append(k + 1).append(") ").append(textLine.replaceFirst(role+": ", "")).append("\n");
                }
            }
            result.append("\n");
        }
        return result.toString();
    }
}
