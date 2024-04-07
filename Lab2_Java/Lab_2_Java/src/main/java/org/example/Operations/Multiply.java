package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.LittleData;
import org.example.Exceptions.ProblemWithDigit;

import java.math.BigDecimal;

public class Multiply implements Operation{
    @Override
    public void Do(Context context, String[] data) {
        if(data.length < 1){
            throw new LittleData();
        }
        if(context.IsEmpty()){
            throw new EmptyStack();
        }


        double answer = 1;
        for(String string_digit : data){
            try{
                double digit = Double.parseDouble(string_digit);
                answer *= digit;
            } catch (NumberFormatException e){
                BigDecimal number = context.FindName(string_digit);
                if(number != null){
                    answer *= number.doubleValue();
                }else{
                    throw new ProblemWithDigit();
                }
            }
        }
        answer *= context.PopDigit().doubleValue();
        context.PushDigit(BigDecimal.valueOf(answer));
    }
}
