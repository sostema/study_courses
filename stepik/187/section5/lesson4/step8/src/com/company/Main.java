package com.company;

import java.io.*;
import java.util.Objects;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    static class Animal implements Serializable {
        private final String name;

        public Animal(String name) {
            this.name = name;
        }

        @Override
        public boolean equals(Object obj) {
            boolean result = false;
            if (obj instanceof Animal) {
                result = Objects.equals(name, ((Animal) obj).name);
            }
            return result;
        }

        public static Animal[] deserializeAnimalArray(byte[] data) {

            try (ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(data))) {
                int deserializedSize = (int) ois.readInt();
                Animal[] animals = new Animal[deserializedSize];
                for (int i = 0; i < deserializedSize; i++) {
                    animals[i] = (Animal) ois.readObject();
                }
                return animals;
            }
            catch (IOException | ClassNotFoundException | ClassCastException ex) {
                throw new IllegalArgumentException(ex.getMessage());
            }
        }
    }
}
