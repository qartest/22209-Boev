package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.LittleData;


public class Print implements Operation{
    @Override
    public void Do(Context context, String[] data) {
        if(context.IsEmpty()){
            throw new EmptyStack();
        }
        System.out.println(context.ShowDigit().doubleValue());
    }
}
