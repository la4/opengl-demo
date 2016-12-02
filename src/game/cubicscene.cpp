#include "cubicscene.h"
#include "cube.h"

CubicScene::CubicScene() {
}

void CubicScene::initialize() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                Cube *cube = new Cube(new Mesh, new Transform);
                cube->getTransform()->setPosition(-25 + i * 5.0, - 25 + j * 5.0, -50 - k * 5.0);
                addObject(cube);
            }
        }
    }
}
