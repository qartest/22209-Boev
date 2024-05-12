package CreeperJump.GameStates;

import CreeperJump.Game.Game;
import CreeperJump.UI.MenuButton;

import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

import static CreeperJump.utilz.Constants.MenuSettings.*;

public class Menu extends State implements Statemethods {

    private MenuButton[] buttons = new MenuButton[MENU_BUTTONS];


    public Menu(Game game) {
        super(game);
        loadButtons();
    }

    private void loadButtons(){
        buttons[0] = new MenuButton(Game.GAME_WIDTH / 2, (GetStateY(0)), 0,  GameState.PLAYING);
        buttons[1] = new MenuButton(Game.GAME_WIDTH / 2, (GetStateY(1)), 1,  GameState.QUIT);
    }
    @Override
    public void update() {
        for(MenuButton mb : buttons){
            mb.update();
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {
        for(MenuButton mb : buttons){
            if(isIn(e, mb)){
                if(mb.isMousePressed())
                    mb.applyGameState();
                break;
            }
        }
        resetButtons();
    }

    private void resetButtons(){
        for(MenuButton mb : buttons){
            mb.resetBools();
        }
    }

    @Override
    public void mousePressed(MouseEvent e) {
        for(MenuButton mb : buttons){
            if(isIn(e, mb)){
                mb.setMousePressed(true);
                break;
            }
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        for(MenuButton mb : buttons){
            mb.setMouseOver(false);
        }

        for(MenuButton mb : buttons){
            if(isIn(e, mb)){
                mb.setMouseOver(true);
                break;
            }
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if(e.getKeyCode() == KeyEvent.VK_ENTER)
            GameState.state = GameState.PLAYING;
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent e) {

    }

    public MenuButton[] getButtons(){
        return buttons;
    }

}
