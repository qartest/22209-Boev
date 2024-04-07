package org.example.Factory;

import org.example.Operations.Operation;

import java.util.Map;

public interface Factory {
    public Operation createOperation(String commandName) throws InstantiationException, IllegalAccessException;
}
