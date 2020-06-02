package com.company;

import java.util.Collection;
import java.util.Comparator;
import java.util.Optional;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static <T> void findMinMax(
            Stream<? extends T> stream,
            Comparator<? super T> order,
            BiConsumer<? super T, ? super T> minMaxConsumer) {

        // your implementation here
        Collection<? extends T> forFindMinMax = stream.collect(Collectors.toList());
        Optional<? extends T> minOpt = forFindMinMax.stream().min(order);
        Optional<? extends T> maxOpt = forFindMinMax.stream().max(order);
        T min = null, max = null;
        if (minOpt.isPresent() & maxOpt.isPresent()) {
            min = minOpt.get();
            max = maxOpt.get();
        }
        minMaxConsumer.accept(min, max);
    }
}
