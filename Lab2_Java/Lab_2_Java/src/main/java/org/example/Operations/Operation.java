package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.MyExceptions;

public interface Operation {
    public void Do(Context context, String[] data) throws MyExceptions;
}
