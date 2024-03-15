package org.Word;

import java.util.*;

public class Word {
    private String word_;
    private int count_;

    private double percent_;

    public int GiveCount(){
        return count_;
    }

    public String GiveWord(){
        return word_;
    }

    public double GivePercent(){return percent_;}
    public void ChangeCount(int count){
        count_ = count;
    }

    public void ChangePercent(double digit){
        percent_ = digit;
    }

    public Word(String name){
        count_ = 1;
        word_ = name;
        percent_ = 0;
    }

    public Word(){
        count_ = 1;
        word_ = "";
        percent_ = 0;
    }

    @Override

    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || getClass() != o.getClass()) return false;

        Word word = (Word) o;
        return Objects.equals(word_, word.word_);
    }

    public int hashCode(){
        return Objects.hash(word_);
    }



}


