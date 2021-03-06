#pragma once

#define PI 3.1415926535897932384626433832795

namespace spat
{
    struct Vec2
    {
        float x;
        float y;
    };

    struct Vec4Color
    {
        float r;
        float g;
        float b;
        float a;
    };

    struct TrigData
    {
        float sind;
        float cosd;
        float degree;
    };

    struct PosSizeData
    {
        Vec2 pos;
        Vec2 size;
    };

    struct VertexElement
    {
        Vec2 Position2D;
        Vec4Color Color;
        Vec2 TexCoords;
        float TexID;
    };

    struct Vertex2D
    {
        VertexElement v0;
        VertexElement v1;
        VertexElement v2;
        VertexElement v3;
    };

    struct VertexSingle2D
    {
        Vec2 v0;
        Vec2 v1;
        Vec2 v2;
        Vec2 v3;
    };
    

    struct VertexCache2D
    {
        Vec2 pos;
        Vec2 hsize; //half size
        TrigData trig;
    };

    struct IndexElement
    {
        unsigned int i0;
        unsigned int i1;
        unsigned int i2;
        unsigned int i3;
        unsigned int i4;
        unsigned int i5;
    };
}