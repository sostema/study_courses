package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {

        InputStream inputStream = System.in;

        try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream, StandardCharsets.UTF_8))) {

            List<String> inputStringList = createListFromString(bufferedReader
                    .readLine()
                    .toLowerCase());
            Map<String, Long> resultMap = new LinkedHashMap<>();

            // Creation a map with keys and value
            Map<String, Long> preparingMap = inputStringList
                    .stream()
                    .collect(
                            Collectors.groupingBy(
                                    Function.identity(),
                                    Collectors.counting()
                            )
                    );


            //Sort a map on the value (primary) and on the keys (secondary) and add to finalMap
            preparingMap.entrySet()
                    .stream()
                    .sorted(Map.Entry
                            .<String, Long>comparingByValue()
                            .reversed()
                            .thenComparing(
                                    Map.Entry.comparingByKey())
                    )
                    .limit(10)
                    .forEachOrdered(
                            e -> resultMap
                                    .put(e.getKey(), e.getValue())
                    );

            resultMap.entrySet().forEach(e -> System.out.println(e.getKey()));

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static List<String> createListFromString(final String inputString) throws IOException {

        if (inputString.length() == 0) {
            throw new IOException(Arrays.toString(new String[]{"The input string is empty"}));
        }

        char[] chars = inputString.toCharArray();
        boolean setNewBeginWord = true;
        int beginOfWord = 0;
        List<String> listString = new ArrayList<>();

        for (int i = 0; i < chars.length; i++) {
            char currentChar = chars[i];
            beginOfWord = setNewBeginWord ? i : beginOfWord;
            setNewBeginWord = false;

            if (!Character.isLetter(currentChar)
                    & !Character.isDigit(currentChar)) {
                setNewBeginWord = true;

                if (i - beginOfWord == 0) {
                    continue;
                } else {
                    listString.add(String.copyValueOf(chars, beginOfWord, i - beginOfWord));
                }

            } else if (i == chars.length - 1) {
                listString.add(String.copyValueOf(chars, beginOfWord, chars.length - beginOfWord));
            }

        }

        return listString;

    }

}