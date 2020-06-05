#include "enemy.h"
#include "mainwindow.h"
#include "waypoint.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>
Enemy::Enemy(WayPoint *startWayPoint, MainWindow *game,
             const QPixmap &sprite/* = QPixmap(":/image/enemy.png")*/,
             int maxHp/* = 40*/, qreal walkingSpeed/* = 1.0*/, int level/*=1*/)
    : QObject(0)
    , m_active(false)
    , m_maxHp(maxHp)
    , m_currentHp(maxHp)
    , m_walkingSpeed(walkingSpeed)
    , m_level(level)
    , m_rotationSprite(0.0)
    , m_pos(startWayPoint->pos())
    , m_destinationWayPoint(startWayPoint->nextWayPoint())
    , m_game(game)
    , m_sprite(sprite)
{
}
