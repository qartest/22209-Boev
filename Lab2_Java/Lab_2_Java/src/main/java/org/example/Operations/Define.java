package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.DigitNotDefine;
import org.example.Exceptions.LittleData;
import org.example.Exceptions.MyExceptions;
import org.example.Exceptions.ProblemWithDigit;

import java.math.BigDecimal;

public class Define implements Operation{

    private static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    @Override
    public void Do(Context context, String[] data) throws MyExceptions {
        if(data.length < 2){
            throw new LittleData();
        }
        if (isNumeric(data[0])){
            throw new DigitNotDefine();
        }

        try{
            double digit = Double.parseDouble(data[1]);
             context.DefineDigit(data[0], BigDecimal.valueOf(digit));
        } catch (NumberFormatException e){
            BigDecimal number = context.FindName(data[1]);
            if(number != null) context.DefineDigit(data[0],number);
            else{
                throw new ProblemWithDigit();
            }
        }
    }
}
