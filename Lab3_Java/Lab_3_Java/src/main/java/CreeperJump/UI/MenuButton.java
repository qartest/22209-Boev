package CreeperJump.UI;

import CreeperJump.GameStates.GameState;

import java.awt.*;
import java.awt.image.BufferedImage;

import static CreeperJump.utilz.Constants.MenuSettings.*;


public class MenuButton {
    private int xPos, yPos, type;
    private int index;
    private int xOffsetCenter;

    private boolean mouseOver = false;
    private boolean mousePressed = false;

    private Rectangle bounds;

    GameState state;


    public MenuButton(int xPos, int yPos, int type, GameState state){
        this.xPos = xPos;
        this.yPos = yPos;
        this.type = type;
        this.xOffsetCenter = GetWidthDefault(type) / 2;
        this.state = state;

        initBounds();
    }

    private void initBounds(){
        bounds = new Rectangle(xPos - xOffsetCenter, yPos, GetWidthDefault(type), B_HEIGHT);
    }

    public void update(){
        index = 0;
        if(mouseOver)
            index = 1;
        if(mousePressed)
            index = 2;
    }

    public boolean isMouseOver() {
        return mouseOver;
    }

    public void setMouseOver(boolean mouseOver) {
        this.mouseOver = mouseOver;
    }

    public boolean isMousePressed() {
        return mousePressed;
    }

    public void setMousePressed(boolean mousePressed) {
        this.mousePressed = mousePressed;
    }

    public void applyGameState(){
        GameState.state = state;
    }

    public void resetBools(){
        mouseOver = false;
        mousePressed = false;
    }

    public Rectangle getBounds(){
        return bounds;
    }

    public int getIndex(){
        return index;
    }
}
