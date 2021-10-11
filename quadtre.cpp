#include "quadtre.h"
#include <iostream>

QuadTre::QuadTre()
{ }

QuadTre::QuadTre(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4)
    : m_a{v1}, m_b{v2}, m_c{v3}, m_d{v4}, m_sv{nullptr}, m_so{nullptr}, m_no{nullptr}, m_nv{nullptr}
{ }

void QuadTre::subDivide(int n)
{
    if (n>0) {
        Vector2d v1 = (m_a+m_b)/2;
        Vector2d v2 = (m_b+m_c)/2;
        Vector2d v3 = (m_c+m_d)/2;
        Vector2d v4 = (m_d+m_a)/2;
        Vector2d m = (m_a+m_c)/2;
        m_sv = new QuadTre (m_a, v1 , m, v4);
        m_sv->subDivide(n-1);
        m_so = new QuadTre(v1 ,m_b, v2, m) ;
        m_so->subDivide(n-1);
        m_no = new QuadTre(m, v2, m_c, v3);
        m_no->subDivide(n-1);
        m_nv = new QuadTre(v4, m, v3, m_d);
        m_nv->subDivide(n-1);
    }
}

bool QuadTre::isLeaf() const
{
    return m_sv == nullptr && m_so == nullptr && m_no == nullptr && m_nv == nullptr;
}

void QuadTre::printLeaf() const
{
    //Hvis dette er et blad, print ut punktene
    if (this->isLeaf())
    std::cout << "(" << m_a.x << "," << m_a.y << ")(" <<m_b.x << "," << m_b.y << ")(" << m_c.x << "," << m_c.y << ")(" << m_d.x << "," << m_d.y << ")" << std::endl;

    //Hvis denne noden har en neste node, kjør samme funksjon i den noden
    if (m_sv)
        m_sv->printLeaf();
    if (m_so)
        m_so->printLeaf();
    if (m_no)
        m_no->printLeaf();
    if (m_nv)
        m_nv->printLeaf();
}

