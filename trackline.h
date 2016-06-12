#ifndef TRACKLINE_H
#define TRACKLINE_H
#include <QPoint>

class trackline
{
public:
    trackline();
    QPoint m_start_point;
    QPoint m_end_point;
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // TRACKLINE_H


