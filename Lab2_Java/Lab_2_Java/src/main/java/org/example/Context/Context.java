package org.example.Context;

import org.example.Exceptions.EmptyStack;

import java.io.IOException;
import java.math.BigDecimal;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Context {
    private Map<String, BigDecimal> define_cash = new HashMap<>();
    private Stack<BigDecimal> stack_digit = new Stack<>();


    public long SizeStack(){
        return stack_digit.size();
    }

    public boolean IsEmpty(){
        return stack_digit.isEmpty();
    }

    public void PushDigit(BigDecimal digit) {
        try{
            stack_digit.push(digit);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void DefineDigit(String name, BigDecimal digit){
        try{
            define_cash.put(name, digit);
        } catch (Exception e){
            throw new RuntimeException(e);
        }
    }

    public BigDecimal PopDigit(){
        if(stack_digit.isEmpty()){
            throw new EmptyStack();
        }
        return stack_digit.pop();
    }

    public BigDecimal ShowDigit(){
        if(stack_digit.isEmpty()){
            throw new EmptyStack();
        }
        return stack_digit.peek();
    }

    public BigDecimal FindName(String name){
        return define_cash.get(name);
    }

}
