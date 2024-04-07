package org.example.Exceptions;

public class EmptyStack extends MyExceptions{
    public EmptyStack(){
    }

    @Override
    public void logMessage() {
        System.out.println("Stack is Empty");
    }

}
