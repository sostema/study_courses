package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    enum Label {
        SPAM, NEGATIVE_TEXT, TOO_LONG, OK
    }

    interface TextAnalyzer {
        Label processText(String text);
    }

    abstract class KeywordAnalyzer implements TextAnalyzer{
        protected abstract String[] getKeywords();

        protected abstract Label getLabel();

        @Override
        public Label processText(String text) {
            for (String key: getKeywords()) {
                if (text.contains(key)) {
                    return getLabel();
                }
            }
            return Label.OK;
        }
    }

     class SpamAnalyzer extends KeywordAnalyzer implements TextAnalyzer {
        public SpamAnalyzer(String[] keywords){
           this.keywords = keywords;
           this.label = Label.SPAM;
        }

        @Override
        protected String[] getKeywords() {
            return keywords;
        }

        @Override
        protected Label getLabel() {
            return label;
        }

         private final String[] keywords;
         private final Label label;
    }

     class NegativeTextAnalyzer extends KeywordAnalyzer implements TextAnalyzer {
        public NegativeTextAnalyzer(){
            this.keywords = new String[] {":(", "=(", ":|"};
            this.label = Label.NEGATIVE_TEXT;
        }

        @Override
        protected String[] getKeywords() {
            return keywords;
        }

        @Override
        protected Label getLabel() {
            return label;
        }
         private final String[] keywords;
         private final Label label;
    }

     class TooLongTextAnalyzer implements TextAnalyzer {
        public TooLongTextAnalyzer(int maxLength){
            this.maxLength = maxLength;
        }

        @Override
        public Label processText(String text) {
            if (text.length() > maxLength){
                return Label.TOO_LONG;
            }
            else {
                return Label.OK;
            }
        }

        private final int maxLength;
    }

    public Label checkLabels(TextAnalyzer[] analyzers, String text) {
        Label label = Label.OK;
        for (TextAnalyzer analyzer: analyzers
             ) {
            label = analyzer.processText(text);
            if(label != Label.OK){
                return label;
            }
        }

        return label;
    }
}
