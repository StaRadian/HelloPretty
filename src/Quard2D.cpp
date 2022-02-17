#include "Quard2D.h"

namespace spat
{
    Quard2D::Quard2D()
        :m_Index0(0)
    {

    }

    Quard2D::~Quard2D()
    {

    }

    Vec2 Quard2D::Vec2Rotation(const Vec2& target, const Vec2& point, const float& degree)
    {
        int sind = SIN(degree);
        int cosd = COS(degree);
        Vec2 result = {
            target.x + point.x * cosd - point.y * sind,
            target.y + point.x * sind + point.y * cosd
        };

        return result;
    }

    void Quard2D::PushIndex()
    {
        m_Index.push_back({m_Index0, m_Index0 + 1, m_Index0 + 2, m_Index0 + 2, m_Index0 + 3, m_Index0});
        m_Index0 += 4;
    }
}