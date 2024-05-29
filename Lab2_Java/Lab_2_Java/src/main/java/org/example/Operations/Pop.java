package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.EmptyStack;

public class Pop implements Operation{
    @Override
    public void Do(Context context, String[] data) {
        if(context.IsEmpty()){
            throw new EmptyStack();
        }
        context.PopDigit();
    }
}
