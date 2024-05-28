package org.example.Factory;

import org.example.Operations.Operation;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class MyFactory implements Factory {
    private final Map<String, Class<? extends Operation>> data = new HashMap<>();
    public MyFactory(String name){
        try {
            loadConfig(name);
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    private void loadConfig(String name) throws IOException, ClassNotFoundException {
        try(InputStream inputStream = MyFactory.class.getResourceAsStream(name)){
            Properties properties = new Properties();
            properties.load(inputStream);

            for(String commandName : properties.stringPropertyNames()){
                String className = properties.getProperty(commandName);

                Class<? extends Operation> commandClass = (Class<? extends Operation>) Class.forName(className);
                data.put(commandName, commandClass);
            }
        }
    }
    @Override
    public  Operation createOperation(String commandName) throws InstantiationException, IllegalAccessException {
        Class<? extends Operation> commandClass = data.get(commandName);
        if(commandClass != null){
            return commandClass.newInstance();
        }
        return null;
    }
}
