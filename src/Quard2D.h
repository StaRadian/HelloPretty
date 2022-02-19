#pragma once

#include "VertexMat.h"
#include <vector>

#include <cmath>
#define SIN(x) sin(x)
#define COS(x) cos(x)

namespace spat
{
    class Quard2D
    {
    private:
        std::vector<IndexElement> m_Index;
        unsigned int m_Index0;
    protected:
        void PushIndex();
    public:
        Quard2D();
        ~Quard2D();
        Vec2 Vec2Rotation(const Vec2& target, const Vec2& point, const double& sind, const double& cosd);

        inline unsigned int *GetIndex() { return &(m_Index[0].i0);};
        inline unsigned int GetIndexSize() const { return m_Index.size() * 6;};
    };
}