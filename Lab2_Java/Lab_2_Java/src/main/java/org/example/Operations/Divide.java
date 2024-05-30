package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.LittleData;
import org.example.Exceptions.MyExceptions;
import org.example.Exceptions.ProblemWithDigit;

import java.math.BigDecimal;

public class Divide implements Operation{

    @Override
    public void Do(Context context, String[] data) throws MyExceptions {

        if((data.length > 0) && (!context.IsEmpty())) {
            double all_minus = 1;
            for(String string_digit : data){
                try{
                    all_minus  *= Double.parseDouble(string_digit);
                } catch (NumberFormatException e){
                    BigDecimal number = context.FindName(string_digit);
                    if(number != null){
                        all_minus *= number.doubleValue();
                    }else{
                        throw new ProblemWithDigit();
                    }
                }
            }
            if(all_minus != 0)
                context.PushDigit(BigDecimal.valueOf(context.PopDigit().doubleValue() / all_minus));
            else{
                throw new ProblemWithDigit();
            }
        }

        else if((data.length == 0) && (context.SizeStack() > 1)){
            double var1 = context.PopDigit().doubleValue();
            double var2 = context.PopDigit().doubleValue();
            if(var2 != 0){
                context.PushDigit(BigDecimal.valueOf(var1 / var2));
            }
            else {
                throw new ProblemWithDigit();
            }
        }
        else{
            throw new LittleData();
        }

    }
}
