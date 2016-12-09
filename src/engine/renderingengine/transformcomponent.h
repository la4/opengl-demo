#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "component.h"

// Base class for any transform components
class TransformComponent : public Component
{
public:
    TransformComponent();
    virtual ~TransformComponent();
};

#endif // TRANSFORMCOMPONENT_H
