//#ifndef WAYPOINT_H
#define WAYPOINT_H


#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QPainter>

// 敌人移动的航线
class WayPoint
{
public:
    WayPoint(QPoint pos);

    void setNextWayPoint(WayPoint *nextPoint);
    WayPoint* nextWayPoint() const;
    const QPoint pos() const;

    void draw(QPainter *painter) const;

private:
    const QPoint _pos;
    WayPoint * _nextWayPoint;
};
