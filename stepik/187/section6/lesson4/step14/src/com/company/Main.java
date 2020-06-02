package com.company;

import java.util.*;
import java.util.function.*;

public class Main {

    public static void main(String[] args) {

        String randomFrom = "...";
        String randomTo = "...";
        int randomSalary = 100;

        MailMessage firstMessage = new MailMessage(
                "Robert Howard",
                "H.P. Lovecraft",
                "This \"The Shadow over Innsmouth\" story is real masterpiece, Howard!"
        );

        assert firstMessage.getFrom().equals("Robert Howard") : "Wrong firstMessage from address";
        assert firstMessage.getTo().equals("H.P. Lovecraft") : "Wrong firstMessage to address";
        assert firstMessage.getContent().endsWith("Howard!") : "Wrong firstMessage content ending";

        MailMessage secondMessage = new MailMessage(
                "Jonathan Nolan",
                "Christopher Nolan",
                "Брат, почему все так хвалят только тебя, когда практически все сценарии написал я. Так не честно!"
        );

        MailMessage thirdMessage = new MailMessage(
                "Stephen Hawking",
                "Christopher Nolan",
                "Я так и не понял Интерстеллар."
        );

        List<MailMessage> messages = Arrays.asList(
                firstMessage, secondMessage, thirdMessage
        );

        MailService<String> mailService = new MailService<>();

        messages.stream().forEachOrdered(mailService);

        Map<String, List<String>> mailBox = mailService.getMailBox();

        assert mailBox.get("H.P. Lovecraft").equals(
                Arrays.asList(
                        "This \"The Shadow over Innsmouth\" story is real masterpiece, Howard!"
                )
        ) : "wrong mailService mailbox content (1)";

        assert mailBox.get("Christopher Nolan").equals(
                Arrays.asList(
                        "Брат, почему все так хвалят только тебя, когда практически все сценарии написал я. Так не честно!",
                        "Я так и не понял Интерстеллар."
                )
        ) : "wrong mailService mailbox content (2)";

        assert mailBox.get(randomTo).equals(Collections.<String>emptyList()) : "wrong mailService mailbox content (3)";


        Salary salary1 = new Salary("Facebook", "Mark Zuckerberg", 1);
        Salary salary2 = new Salary("FC Barcelona", "Lionel Messi", Integer.MAX_VALUE);
        Salary salary3 = new Salary(randomFrom, randomTo, randomSalary);

        MailService<Integer> salaryService = new MailService<>();

        Arrays.asList(salary1, salary2, salary3).forEach(salaryService);

        Map<String, List<Integer>> salaries = salaryService.getMailBox();
        assert salaries.get(salary1.getTo()).equals(Arrays.asList(1)) : "wrong salaries mailbox content (1)";
        assert salaries.get(salary2.getTo()).equals(Arrays.asList(Integer.MAX_VALUE)) : "wrong salaries mailbox content (2)";
        assert salaries.get(randomTo).equals(Arrays.asList(randomSalary)) : "wrong salaries mailbox content (3)";
    }

    public static interface Sendable<T> {
        String getFrom();

        String getTo();

        T getContent();
    }

    public static class SimpleSendable<T> implements Sendable<T> {
        private String from, to;
        private T content;

        public SimpleSendable(String from, String to, T content) {
            this.from = from;
            this.to = to;
            this.content = content;
        }

        @Override
        public String getFrom() {
            return from;
        }

        @Override
        public String getTo() {
            return to;
        }

        @Override
        public T getContent() {
            return content;
        }
    }

    public static class MailMessage extends SimpleSendable<String> {
        public MailMessage(String from, String to, String content) {
            super(from, to, content);
        }
    }

    public static class Salary extends SimpleSendable<Integer> {
        public Salary(String from, String to, Integer content) {
            super(from, to, content);
        }
    }

    public static class MailService<T> implements Consumer<Sendable<T>> {
        private Map<String, List<T>> messagesMap = new HashMap<String, List<T>>() {
            @Override
            public List<T> get(Object key) {
                if (this.containsKey(key)) {
                    return super.get(key);
                } else {
                    return Collections.emptyList();
                }
            }
        };

        @Override
        public void accept(Sendable<T> sendable) {
            List<T> ts = messagesMap.get(sendable.getTo());
            if (ts.size() == 0) {
                ts = new ArrayList<>();
            }
            ts.add(sendable.getContent());
            messagesMap.put(sendable.getTo(), ts);
        }

        public Map<String, List<T>> getMailBox() {
            return messagesMap;
        }
    }
}
