#ifndef QUADTRE_H
#define QUADTRE_H
#include <vector>
#include "Vector2d.h"

class QuadTre
{
private:
    Vector2d m_a;
    Vector2d m_b;
    Vector2d m_c;
    Vector2d m_d;
    QuadTre* m_sv;
    QuadTre* m_so ;
    QuadTre* m_no;
    QuadTre* m_nv;

    bool isLeaf() const;
public:
QuadTre();
QuadTre(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4);
void subDivide (int n);
void printLeaf() const;
};

#endif // QUADTRE_H
