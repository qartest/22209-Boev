package org.example.Exceptions;

public class ExitException extends RuntimeException{
    public void logMessage() {
        System.out.println("Exit");
    }
}
