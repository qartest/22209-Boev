package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;
import org.example.Exceptions.MyExceptions;

public class Pop implements Operation{
    @Override
    public void Do(Context context, String[] data) throws MyExceptions {
        if(context.IsEmpty()){
            throw new EmptyStack();
        }
        context.PopDigit();
    }
}
