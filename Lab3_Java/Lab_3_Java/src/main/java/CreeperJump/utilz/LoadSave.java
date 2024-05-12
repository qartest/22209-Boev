package CreeperJump.utilz;

import CreeperJump.Game.Game;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.InputStream;

public class LoadSave {

    public static final String PLAYER_ATLAS = "player_sprites.png" ;
    public static final String LEVEL_ATLAS = "img.png" ;
    public static final String LEVEL_ONE_DATA = "level_one_data.png" ;
    public static final String  MENU_BACKGROUND = "menu_background.png";
    public static final String  PAUSE_BACKGROUND = "pause_menu.png";
    public static final String SOUND_BUTTONS = "sound_button.png";
    public static final String URM_BUTTONS = "urm_buttons.png";
    public static final String VOLUME_BUTTONS = "volume_buttons.png";


    public static final String COBBLE_STEPS = "cobble_step.png";
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
