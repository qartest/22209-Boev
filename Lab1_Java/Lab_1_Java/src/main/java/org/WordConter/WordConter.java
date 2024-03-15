package org.WordConter;

import org.Word.Word;

import java.io.IOException;
import java.io.Reader;
import java.util.*;

import java.util.Comparator;

public class WordConter {
    public ArrayList<Word> Do(Reader reader){

        double all_words = 0;

        Map<Word, Integer> word_map = new HashMap<>();
        StringBuilder word_build = new StringBuilder();

        int charCode;
        String word;

        while(true){
            try {
                if ((charCode = reader.read()) == -1) break;
                if(Character.isLetterOrDigit(charCode)){
                    word_build.append((char) charCode);
                }
                else{
                    word = word_build.toString();
                    word_build.delete(0, word_build.length());

                    if(!word.isEmpty()){

                        Word class_word = new Word(word);

                        int new_value = 1;

                        Integer now_value = word_map.get(class_word);
                        if(now_value != null){
                            new_value += now_value;
                        }

                        word_map.put(class_word, new_value);
                        ++all_words;

                    }
                }

            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        }

        Comparator<Word> comporator = (o1, o2) -> Integer.compare(o2.GiveCount(), o1.GiveCount());
        ArrayList<Word> my_set = new ArrayList<>();

        for(Map.Entry<Word, Integer> entry : word_map.entrySet()) {
           Word now_word = entry.getKey();
           int now_count = entry.getValue();

           now_word.ChangeCount(now_count);
           now_word.ChangePercent(((double)now_count) / all_words);

           my_set.add(now_word);
        }
        my_set.sort(comporator);

        return my_set;
    }
}
