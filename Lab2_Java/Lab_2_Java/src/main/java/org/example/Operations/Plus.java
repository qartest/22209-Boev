package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.LittleData;
import org.example.Exceptions.MyExceptions;
import org.example.Exceptions.ProblemWithDigit;

import java.math.BigDecimal;
public class Plus implements Operation{
    public Plus(){
    }
    @Override
    public void Do(Context context, String[] data) throws MyExceptions {

        if((data.length > 0) && (!context.IsEmpty())) {
            double answer = 0;
            for(String string_digit : data){
                try{
                    double digit = Double.parseDouble(string_digit);
                    answer += digit;
                } catch (NumberFormatException e){
                    BigDecimal number = context.FindName(string_digit);
                    if(number != null){
                        answer += number.doubleValue();
                    }else{
                        throw new ProblemWithDigit();
                    }
                }
            }
            double stack_digit = context.PopDigit().doubleValue();
            answer += stack_digit;
            context.PushDigit(BigDecimal.valueOf(answer));
        }

        else if((data.length == 0) && (context.SizeStack() > 1)){
            double var1 = context.PopDigit().doubleValue();
            double var2 = context.PopDigit().doubleValue();

            double answer = var1 + var2;
            context.PushDigit(BigDecimal.valueOf(answer));
        }

        else{
            throw new LittleData();
        }

    }
}
