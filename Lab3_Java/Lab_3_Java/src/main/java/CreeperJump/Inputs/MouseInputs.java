package CreeperJump.Inputs;

import CreeperJump.Game.GamePanel;
import CreeperJump.GameStates.GameState;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class MouseInputs implements MouseListener, MouseMotionListener {

    private GamePanel gamePanel;
    public MouseInputs(GamePanel gamePanel){
        this.gamePanel = gamePanel;
    }

    @Override
    public void mouseClicked(MouseEvent mouseEvent) {
        switch (GameState.state){
            case PLAYING:
//                gamePanel.getGame().getPlaying().mouseClicked(mouseEvent);
                break;
            default:
                break;
        }
    }

    @Override
    public void mousePressed(MouseEvent mouseEvent) {
        switch (GameState.state) {
            case MENU:
                gamePanel.getGame().getMenu().mousePressed(mouseEvent);
                break;
            case PLAYING:
                gamePanel.getGame().getPlaying().mousePressed(mouseEvent);
                break;
            default:
                break;
        }
    }
    @Override
    public void mouseReleased(MouseEvent mouseEvent) {
        switch (GameState.state) {
            case MENU:
                gamePanel.getGame().getMenu().mouseReleased(mouseEvent);
                break;
            case PLAYING:
                gamePanel.getGame().getPlaying().mouseReleased(mouseEvent);
                break;
            default:
                break;
        }
    }

    @Override
    public void mouseEntered(MouseEvent mouseEvent) {

    }

    @Override
    public void mouseExited(MouseEvent mouseEvent) {

    }

    @Override
    public void mouseDragged(MouseEvent mouseEvent) {
        switch (GameState.state) {
            case MENU:
                break;
            case PLAYING:
                gamePanel.getGame().getPlaying().mouseDragged(mouseEvent);
                break;
            default:
                break;
        }
    }

    @Override
    public void mouseMoved(MouseEvent mouseEvent) {
        switch (GameState.state){
            case MENU:
                gamePanel.getGame().getMenu().mouseMoved(mouseEvent);
                break;
            case PLAYING:
                gamePanel.getGame().getPlaying().mouseMoved(mouseEvent);
                break;
            default:
                break;
        }
    }
}
