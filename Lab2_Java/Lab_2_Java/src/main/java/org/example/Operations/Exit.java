package org.example.Operations;

import org.example.Context.Context;
import org.example.Exceptions.ExitException;

public class Exit implements Operation{
    @Override
    public void Do(Context context, String[] data) {
        throw new ExitException();
    }
}
