// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#pragma once
#include <vector>
#include "Object3D.hpp"

class Scene
{
public:
    std::vector<Object3D> objects;

    Object3D &AddObject(const std::string &path, Vec3d pos);
};