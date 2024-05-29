package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;


import java.math.BigDecimal;


public class Sqrt implements Operation {
    @Override
    public void Do(Context context, String[] data) {
        if(context.IsEmpty()){
            throw new EmptyStack();
        }
        double answer = context.PopDigit().doubleValue();
        context.PushDigit(BigDecimal.valueOf(Math.sqrt(answer)));
    }
}
