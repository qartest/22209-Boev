package CreeperJump.GameObjects;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public abstract class GameObjects {
    protected int health;
    protected float x, y;
    protected int width, height;
    protected Rectangle2D.Float hitBox;

    protected Rectangle2D.Float secondHitBox;

    public GameObjects(float x, float y, int width, int height){
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;

    }
    protected void drawHitBox(Graphics g){
        g.setColor(Color.RED);
        g.drawRect((int)hitBox.x, (int)hitBox.y, (int)hitBox.width, (int)hitBox.height);
    }

    protected void initHitbox(float x, float y, int width, int height){
        hitBox = new Rectangle2D.Float((int) x, (int)y, width, height);
    }

    protected void initSecondInitHitBox(float x, float y, int width, int height){
        secondHitBox = new Rectangle2D.Float(x, y, width, height);
    }

    public Rectangle2D.Float getHitBox(){
        return hitBox;
    }

    public Rectangle2D.Float getSecondHitBox(){
        return secondHitBox;
    }

    public int getHealth(){
        return health;
    }

    public void minusHealth(){
        health -= 1;
    }
}
