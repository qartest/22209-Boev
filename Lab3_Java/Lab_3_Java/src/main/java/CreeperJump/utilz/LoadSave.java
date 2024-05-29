package CreeperJump.utilz;

import CreeperJump.Game.Game;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.InputStream;

public class LoadSave {

    public static final String CREEPER = "Creeper.png";
    public static final String  MENU_BUTTONS = "button_atlas.png";
    public static final String MENU_BACK = "menu_back.png";

    public static BufferedImage GetSpriteAtlas(String fileName){
        BufferedImage img = null;
        InputStream is = LoadSave.class.getResourceAsStream("/" + fileName);
        try{
            img = ImageIO.read(is);
        } catch (IOException e){
            e.printStackTrace();
        } finally {
            try {
                is.close();
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        return img;
    }
}
