package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(isPalindrome("!ada."));
    }
    /**
     * Checks if given <code>text</code> is a palindrome.
     *
     * @param text any string
     * @return <code>true</code> when <code>text</code> is a palindrome, <code>false</code> otherwise
     */
    public static boolean isPalindrome(String text) {
        text = text.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");
        StringBuilder reversed_text = new StringBuilder(text);
        reversed_text.reverse();
        return text.equals(reversed_text.toString());
    }
}
