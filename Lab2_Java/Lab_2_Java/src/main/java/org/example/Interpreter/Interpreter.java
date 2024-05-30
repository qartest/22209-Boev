package org.example.Interpreter;

import org.example.Context.Context;
import org.example.Exceptions.ExitException;
import org.example.Exceptions.MyExceptions;
import org.example.Factory.MyFactory;
import org.example.Input.Input;
import org.example.Input.Mode;
import org.example.Operations.Operation;

import java.io.IOException;

public class Interpreter {
    Context context;
    Input input;
    MyFactory factory;

    public Interpreter(Context context, Input input, MyFactory myFactory){
        this.context = context;
        this.input = input;
        this.factory = myFactory;
    }

    public void run() throws InstantiationException, IllegalAccessException{
        String string;
        try{
            while((string = input.reader.readLine()) != null){

                if(string.length() > 0){
                    if(string.charAt(0) == '#'){
                        continue;
                    }
                }

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
