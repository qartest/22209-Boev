package CreeperJump.Game;

import CreeperJump.GameObjects.GameObjects;
import CreeperJump.GameObjects.Player;
import CreeperJump.UI.MenuButton;
import CreeperJump.utilz.LoadSave;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

import static CreeperJump.utilz.Constants.MenuSettings.*;
import static CreeperJump.utilz.Constants.PlayerConstants.MAX_SIZE_MOVE;
import static CreeperJump.utilz.Constants.PlayerConstants.SIZE_MOVES;
import static CreeperJump.utilz.Constants.PlayerSize.PLAYER_HEIGHT_DEFAULT;
import static CreeperJump.utilz.Constants.PlayerSize.PLAYER_WIDTH_DEFAULT;


public class Render {
//    private BufferedImage ImageCoobleSteps = LoadSave.GetSpriteAtlas(LoadSave.COBBLE_STEPS);

    private BufferedImage[][] animationsCreeper;
    private BufferedImage[][] menuButtons;
    private BufferedImage menuBack;

    public Render(){
        loadAnimations();
    }

    public void renderSteps(Graphics g, ArrayList<GameObjects> obj, int GameScore){
        g.setColor(Color.black);
        for(GameObjects ob : obj){
//            g.drawImage(ImageCoobleSteps, (int)ob.getHitBox().x, (int)ob.getHitBox().y, (int)ob.getHitBox().width, (int)ob.getHitBox().height, null);
            g.fillRect((int)ob.getHitBox().x, (int)ob.getHitBox().y + GameScore, (int)ob.getHitBox().width, (int)ob.getHitBox().height);
        }
    }

    public void renderPlayer(Graphics g, Player player, int GameScore){
        g.drawImage(animationsCreeper[player.getPlayerAction()][player.getAniIndex()], (int)(player.getHitBox().getX()), (int)(player.getHitBox().getY() + GameScore), (int)player.getHitBox().getWidth(), (int)player.getHitBox().getHeight(), null);

        if(player.getDivideCreeper())
            g.drawImage(animationsCreeper[player.getPlayerAction()][player.getAniIndex()], (int)(player.getSecondHitBox().getX()), (int)(player.getSecondHitBox().getY() + GameScore), (int)player.getSecondHitBox().getWidth(), (int)player.getSecondHitBox().getHeight(), null);
    }

    private void loadAnimations(){
        loadCreeper();
        loadMenuButtons();
        loadMenuBack();

    }

    private void loadCreeper(){
        BufferedImage img = LoadSave.GetSpriteAtlas(LoadSave.CREEPER);
        animationsCreeper = new BufferedImage[SIZE_MOVES][MAX_SIZE_MOVE];
        for(int j = 0; j < animationsCreeper.length; j++){
            for(int i = 0; i < animationsCreeper[j].length; ++i){
                animationsCreeper[j][i] = img.getSubimage(i *  PLAYER_WIDTH_DEFAULT , j * PLAYER_HEIGHT_DEFAULT, PLAYER_WIDTH_DEFAULT, PLAYER_HEIGHT_DEFAULT);
            }
        }
    }

    private void loadMenuButtons(){
        BufferedImage img = LoadSave.GetSpriteAtlas(LoadSave.MENU_BUTTONS);
        menuButtons = new BufferedImage[MENU_BUTTONS][MENU_ANI_BUTTON];

        for(int j = 0; j < menuButtons.length; j++){
            for(int i = 0; i < menuButtons[j].length; ++i){
                menuButtons[j][i] = img.getSubimage(GetWidthDefault(j) * i  , j * B_HEIGHT_DEFAULT, GetWidthDefault(j), B_HEIGHT_DEFAULT);
            }
        }
    }

    private void loadMenuBack(){
        menuBack = LoadSave.GetSpriteAtlas(LoadSave.MENU_BACK);
    }

    public void renderMenu(Graphics g, MenuButton[] buttons){
        g.drawImage(menuBack, 0, 0, Game.GAME_WIDTH, Game.GAME_HEIGHT, null);

        for(int i = 0; i < buttons.length; ++i){
            g.drawImage(menuButtons[i][buttons[i].getIndex()],  (int)buttons[i].getBounds().getX(), GetStateY(i), GetWidth(i), B_HEIGHT, null);
            }

    }

}
