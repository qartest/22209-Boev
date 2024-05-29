package org.example;

import org.example.Context.Context;
import org.example.Exceptions.ExitException;
import org.example.Exceptions.MyExceptions;
import org.example.Factory.MyFactory;
import org.example.Input.Input;
import org.example.Input.Mode;
import org.example.Operations.Operation;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws InstantiationException, IllegalAccessException {
        ///Контекст хранит элементы массива и переименованные элементы
        MyFactory factory = new MyFactory();
        Context context = new Context();
        Input input = new Input(args);
        String string;
        try{
            while((string = input.reader.readLine()) != null){
                String[] parts = string.split("\\s+");

                Operation operation = factory.createOperation(parts[0]);
                String[] params = new String[parts.length - 1];
                System.arraycopy(parts, 1, params, 0, params.length);

                try{
                    operation.Do(context, params);
                    if (input.mode == Mode.ONLINE){
                        System.out.println("SUCCESSFULLY");
                    }
                }catch(NullPointerException e){
                    System.out.println("Unknown command, sorry man))");
                }catch (ExitException e){
                    e.logMessage();
                    break;
                }
                catch (MyExceptions exceptions){
                    exceptions.logMessage();
                    System.out.println("NOT SUCCESSFULLY(((");
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}