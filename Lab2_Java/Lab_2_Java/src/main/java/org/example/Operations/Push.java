package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.LittleData;
import org.example.Exceptions.ProblemWithDigit;

import java.math.BigDecimal;

public class Push implements Operation {
    @Override
    public void Do(Context context, String[] data) {
        if(data.length < 1){
            throw new LittleData();
        }

        for(String string_digit : data){
            try{
                double digit = Double.parseDouble(string_digit);
                context.PushDigit(BigDecimal.valueOf(digit));
            } catch (NumberFormatException e){
                BigDecimal number = context.FindName(string_digit);
                if(number != null){
                    context.PushDigit(number);
                }else{
                    throw new ProblemWithDigit();
                }
            }
        }
    }
}
