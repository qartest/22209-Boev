package CreeperJump.GameObjects;

public class JumpStep extends GameObjects{

    public JumpStep(float x, float y, int width, int height) {
        super(x, y, width, height);
        initHitbox(x, y, width, height);
        health = 1;

    }
}
