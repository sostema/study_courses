package com.company;

import java.util.Objects;

public class Main {

    public static void main(String[] args) {
        // write your code here
    }

}

class Pair<X, Y> {
    X x;
    Y y;

    private Pair(X x, Y y) {
        this.x = x;
        this.y = y;
    }

    public static <X, Y> Pair<X, Y> of(X x, Y y) {
        return new Pair<X, Y>(x, y);
    }

    public X getFirst() {
        return x;
    }

    public Y getSecond() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return Objects.equals(x, pair.getFirst()) &&
                Objects.equals(y, pair.getSecond());
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
