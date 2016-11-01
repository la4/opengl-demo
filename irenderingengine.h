#ifndef IRENDERINGENGINE_H
#define IRENDERINGENGINE_H

struct IRenderingEngine{
    virtual void initialize(int width, int height) = 0;
    virtual void render() const = 0;
    virtual void updateAnimation(int timeStep) = 0;
    virtual void setAnimating(bool animating) = 0;
    virtual ~IRenderingEngine() {}
};

struct IRenderingEngine *createRenderer();

#endif // IRENDERINGENGINE_H
