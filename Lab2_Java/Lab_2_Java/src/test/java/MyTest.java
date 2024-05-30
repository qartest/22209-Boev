import org.example.Context.Context;
import org.example.Factory.MyFactory;
import org.example.Input.Input;
import org.example.Interpreter.Interpreter;
import org.example.Main;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;

import java.io.*;
import java.util.stream.Stream;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

import static org.junit.Assert.assertThrows;

public class MyTest {
    public static final String commands = "#Comment\nPRINT\nPOP\n* 10\n+ 10\n- 10\n/ 10\nSQRT\nDEFINE A 10\nPUSH A\nPUSH 10\n" +
            "+ \nPUSH 10\n* \n-\nDEFINE 10 10\nCOC\nPRINT\nSQRT\nPUSH CKC\n+ A 10 A\nPOP\n+ CKC\nDEFINE AF AF\nPUSH 10\n* A 10\n/ A 10\n- A 10\n-\n" +
            "PUSH 10\n-\nPUSH 10\n/\n/ 0\n+ 10 KIK\n- 10 KIK\n* 10 KIK\n/ 10 KIK\nPUSH 0\nPUSH 10\n/\nPUSH\nDEFINE\nEXIT";
    public static final String exit = "EXIT";

    @Test
    public void Test1() {
        System.out.println("======TEST ONE EXECUTED=======");
        String[] string = new String[0];
        ByteArrayInputStream input = new ByteArrayInputStream(commands.getBytes(StandardCharsets.UTF_8));
        System.setIn(input);

        try{
            Main.main(string);

        }catch (InstantiationException e){
            throw new RuntimeException(e);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }

    }


    @Test
    public void Test2() {
        System.out.println("======TEST TWO EXECUTED=======");
        String[] strings = new String[1];
        strings[0] = "Bad Name";
        ByteArrayInputStream input = new ByteArrayInputStream(exit.getBytes(StandardCharsets.UTF_8));
        System.setIn(input);

        try{
            Main.main(strings);
        } catch (InstantiationException e) {
            throw new RuntimeException(e);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
    }


    @Test
    public void Test3() {
        String name = "/Commands.properties";
        MyFactory factory = new MyFactory(name);
        Context context = new Context();
        String[] args = new String[0];

        assertThrows(RuntimeException.class, () -> {
            Input input = new Input(args);
            input.giveReader(new BadReader(new InputStreamReader(System.in)));
            Interpreter interpreter = new Interpreter(context, input, factory);
            interpreter.run();
        });
    }


    @Test
    public void Test4(){
        Main.name = "/Commands2.properties";
        String[] string = new String[0];
        assertThrows(RuntimeException.class, () -> {
            Main.main(string);
        });

    }

}