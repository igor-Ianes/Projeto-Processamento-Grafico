// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef _MESH_H
#define _MESH_H

#include <vector>
#include <fstream>
#include <sstream>
#include "math3d.hpp"

struct Mesh
{
    std::vector<Triangle> tris;

    bool LoadFromObjectFile(std::string filename)
    {
        std::ifstream f(filename);
        if (!f.is_open())
            return false;

        std::vector<Vec3d> verts;
        std::vector<vec2d> texs;

        while (!f.eof())
        {
            char line[128];
            f.getline(line, 128);

            std::stringstream s(line);

            std::string prefix;
            s >> prefix;

            // Vertice
            if (prefix == "v")
            {
                Vec3d v;
                s >> v.x >> v.y >> v.z;
                verts.push_back(v);
            }

            // Textura UV, se existir
            else if (prefix == "vt")
            {
                vec2d t;
                s >> t.u >> t.v;
                texs.push_back(t);
            }

            // Faces
            else if (prefix == "f")
            {
                int v[3] = {0, 0, 0};
                int t[3] = {0, 0, 0};

                for (int i = 0; i < 3; i++)
                {
                    std::string token;
                    s >> token;

                    // formato: v/vt/vn ou v/vt ou v//vn ou v
                    std::stringstream ss(token);

                    std::string vStr, tStr, nStr;

                    std::getline(ss, vStr, '/');
                    std::getline(ss, tStr, '/');
                    std::getline(ss, nStr, '/');

                    if (!vStr.empty())
                        v[i] = std::stoi(vStr);

                    if (!tStr.empty())
                        t[i] = std::stoi(tStr);
                }

                Triangle tri;

                // Seguindo formato obj
                if (v[0] <= 0 || v[1] <= 0 || v[2] <= 0)
                    continue;

                tri.p[0] = verts[v[0] - 1];
                tri.p[1] = verts[v[1] - 1];
                tri.p[2] = verts[v[2] - 1];

                // Textura se existir
                if (!texs.empty() && t[0] > 0 && t[1] > 0 && t[2] > 0)
                {
                    tri.t[0] = texs[t[0] - 1];
                    tri.t[1] = texs[t[1] - 1];
                    tri.t[2] = texs[t[2] - 1];
                }
                else
                {
                    tri.t[0] = {0, 0};
                    tri.t[1] = {0, 0};
                    tri.t[2] = {0, 0};
                }

                std::swap(tri.p[1], tri.p[2]);
                std::swap(tri.t[1], tri.t[2]);

                tris.push_back(tri);
            }
        }

        return true;
    }
};

#endif