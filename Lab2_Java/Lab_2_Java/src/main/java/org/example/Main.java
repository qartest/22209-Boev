package org.example;

import org.example.Context.Context;
import org.example.Exceptions.ExitException;
import org.example.Exceptions.MyExceptions;
import org.example.Factory.MyFactory;
import org.example.Input.Input;
import org.example.Input.Mode;
import org.example.Interpreter.Interpreter;
import org.example.Operations.Operation;

import java.io.IOException;

public class Main {
    static public String name = "/Commands.properties";
    public static void main(String[] args) throws InstantiationException, IllegalAccessException {
        ///Контекст хранит элементы массива и переименованные элементы
        MyFactory factory = new MyFactory(name);
        Context context = new Context();


        try(Input input = new Input(args)){
            Interpreter interpreter = new Interpreter(context, input, factory);
            interpreter.run();
        } catch (Exception e) {
        }


    }
}