package CreeperJump.GameObjects;

public class CobbleStep extends GameObjects{

    public CobbleStep(float x, float y, int width, int height) {
        super(x, y, width, height);
        initHitbox(x, y, width, height);
    }
}
