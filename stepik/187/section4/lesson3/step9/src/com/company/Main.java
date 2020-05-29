package com.company;

import java.util.Objects;
import java.util.logging.Logger;

public class Main {

    public static void main(String[] args) {
        // write your code here
    }

    public static final String AUSTIN_POWERS = "Austin Powers";
    public static final String WEAPONS = "weapons";
    public static final String BANNED_SUBSTANCE = "banned substance";

    /**
     * Интерфейс: сущность, которую можно отправить по почте.
     * У такой сущности можно получить от кого и кому направляется письмо.
     */
    public interface Sendable {
        String getFrom();

        String getTo();
    }

    /**
     * Интерфейс, который задает класс,
     * который может каким-либо образом обработать почтовый объект.
     */
    public interface MailService {
        Sendable processMail(Sendable mail);
    }

    /**
     * Абстрактный класс,который позволяет абстрагировать логику хранения
     * источника и получателя письма в соответствующих полях класса.
     */
    public static abstract class AbstractSendable implements Sendable {

        protected final String from;
        protected final String to;

        public AbstractSendable(String from, String to) {
            this.from = from;
            this.to = to;
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
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            AbstractSendable that = (AbstractSendable) o;

            if (!from.equals(that.from)) return false;
            return to.equals(that.to);
        }
    }

    /**
     * Письмо, у которого есть текст,
     * который можно получить с помощью метода `getMessage`
     */
    public static class MailMessage extends AbstractSendable {

        private final String message;

        public MailMessage(String from, String to, String message) {
            super(from, to);
            this.message = message;
        }

        public String getMessage() {
            return message;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            if (!super.equals(o)) return false;

            MailMessage that = (MailMessage) o;

            return Objects.equals(message, that.message);
        }

    }

    /**
     * Посылка, содержимое которой можно получить с помощью метода `getContent`
     */
    public static class MailPackage extends AbstractSendable {
        private final Package content;

        public MailPackage(String from, String to, Package content) {
            super(from, to);
            this.content = content;
        }

        public Package getContent() {
            return content;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            if (!super.equals(o)) return false;

            MailPackage that = (MailPackage) o;

            return content.equals(that.content);
        }

    }

    /**
     * Класс, который задает посылку.
     * У посылки есть текстовое описание содержимого и целочисленная ценность.
     */
    public static class Package {
        private final String content;
        private final int price;

        public Package(String content, int price) {
            this.content = content;
            this.price = price;
        }

        public String getContent() {
            return content;
        }

        public int getPrice() {
            return price;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Package aPackage = (Package) o;

            if (price != aPackage.price) return false;
            return content.equals(aPackage.content);
        }
    }

    /**
     * Класс, в котором скрыта логика настоящей почты
     */
    public static class RealMailService implements MailService {

        @Override
        public Sendable processMail(Sendable mail) {
            // Здесь описан код настоящей системы отправки почты.
            return mail;
        }
    }

    public static class StolenPackageException extends RuntimeException {}
    public static class IllegalPackageException extends RuntimeException {}

    public static class UntrustworthyMailWorker implements MailService {
        protected final MailService[] mailServices;
        protected final RealMailService realMailService;

        public UntrustworthyMailWorker(MailService[] mailServices){
            this.mailServices = mailServices;
            this.realMailService = new RealMailService();
        }

        public RealMailService getRealMailService() {
            return realMailService;
        }

        @Override
        public Sendable processMail(Sendable mail) {
            Sendable current_mail = mail;
            for (MailService mailService : mailServices) {
                current_mail = mailService.processMail(current_mail);
            }
            current_mail = realMailService.processMail(current_mail);
            return current_mail;
        }
    }

    public static class Spy implements MailService {
        protected final Logger logger;

        public Spy(Logger logger){
            this.logger = logger;
        }

        @Override
        public Sendable processMail(Sendable mail) {
            if (mail instanceof MailMessage){
                if (mail.getFrom().equals(AUSTIN_POWERS)
                        || mail.getTo().equals(AUSTIN_POWERS)){
                    logger.warning("Detected target mail correspondence: " +
                            "from " + mail.getFrom() + " to " + mail.getTo() + " \"" + ((MailMessage) mail).message + "\"");
                }
                else {
                    logger.info("Usual correspondence: " +
                            "from " + mail.getFrom() + " to " + mail.getTo());
                }
            }
            return mail;
        }
    }

    public static class Thief implements MailService {
        protected final int minMailCost;
        protected int sumMailCost;

        public Thief(int minMailCost){
            this.minMailCost = minMailCost;
            this.sumMailCost = 0;
        }

        public int getStolenValue(){
            return sumMailCost;
        }

        @Override
        public Sendable processMail(Sendable mail) {
            if (mail instanceof MailPackage){
                MailPackage mailPackage = (MailPackage) mail;
                if (mailPackage.content.price >= minMailCost){
                    sumMailCost += mailPackage.getContent().getPrice();
                    Package newContent = new Package("stones instead of " + ((MailPackage) mail).getContent().getContent(), 0);
                    mail = new MailPackage(mailPackage.getFrom(), mailPackage.getTo(), newContent);
                }
            }
            return mail;
        }
    }

    public static class Inspector implements MailService {

        @Override
        public Sendable processMail(Sendable mail) {
            if (mail.getClass() == MailPackage.class){
                MailPackage mailPackage = (MailPackage) mail;
                if (mailPackage.content.content.contains("stones")){
                    throw new StolenPackageException();
                }
                else if (mailPackage.content.content.contains(WEAPONS) || mailPackage.content.content.contains(BANNED_SUBSTANCE)){
                    throw new IllegalPackageException();
                }
            }
            return mail;
        }
    }


}
