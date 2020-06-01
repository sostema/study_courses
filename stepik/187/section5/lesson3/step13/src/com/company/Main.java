package com.company;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    private static Double readAsDoubleSum(final String inputString) {
        double resultDouble = 0.000000;
        String resultString;
        int beginIndex = 0; byte currentByte;
        boolean indexOfFirstWordsChar = true, wordHasNonNumeCharacter = false,
                wordHasOneCharacterE = false, wordHasOneCharacterDot = false;
        byte[] bytes = inputString.getBytes(), bytes1;
        for (int i = 0; i < bytes.length; i++) {
            currentByte = bytes[i];
            if ((currentByte > 47 & currentByte < 58) | (currentByte > 44 & currentByte < 47)) {
                if (indexOfFirstWordsChar) {
                    beginIndex = i;
                    indexOfFirstWordsChar = false;
                }
            } else if (currentByte == 32 | currentByte == 10) {
                indexOfFirstWordsChar = true;
                if (!wordHasNonNumeCharacter) {
                    bytes1 = Arrays.copyOfRange(bytes, beginIndex, i);
                    resultString = new String(bytes1, StandardCharsets.UTF_8);
                    resultDouble += Double.parseDouble(resultString);
                }
                wordHasNonNumeCharacter = false;
                wordHasOneCharacterE = false;
                wordHasOneCharacterDot = false;
            } else {
                if (currentByte == 101) {
                    if (!wordHasOneCharacterE) {
                        wordHasOneCharacterE = true;
                    } else {
                        wordHasNonNumeCharacter = true;
                    }
                } else if (currentByte == 46) {
                    if (!wordHasOneCharacterDot) {
                        wordHasOneCharacterDot = true;
                    } else {
                        wordHasNonNumeCharacter = true;
                    }
                } else {
                    wordHasNonNumeCharacter = true;
                }
            }
        }
        return resultDouble;
    }
}
