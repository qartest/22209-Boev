package org.example.Exceptions;

public class DigitNotDefine extends MyExceptions{
    @Override
    public void logMessage() {
        System.out.println("A number cannot be a name");
    }
}
