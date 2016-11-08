#ifndef IRENDERINGENGINE_H
#define IRENDERINGENGINE_H

#include <QtGlobal>
#include "rendersettingsinitializations.h"

struct IRenderingEngine{
    virtual void initialize( const RenderSettingsInitializations& settings ) = 0;
    virtual void render() = 0;
    virtual void updateAnimation( int timeStep ) = 0;
    virtual void setAnimating( bool animating ) = 0;
    virtual ~IRenderingEngine() {}
};

struct IRenderingEngine *createRenderer();

#endif // IRENDERINGENGINE_H
