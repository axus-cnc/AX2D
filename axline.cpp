#include "AxLine.h"
#include <QPainter>
#include "math.h"


/*AxLine :: AxLine(const QLine &line_test)
{
    QLine line_trans(line_test);
    limits=line_trans;

}*/

AxLine::AxLine(AxBorder *border)
{
    limits=QLine(border->x1(),border->y1(),border->x2(),border->y2());

}

AxLine::AxLine(QLine _line)
{
    limits=_line;
}

AxLine ::AxLine(int x1, int y1, int x2, int y2)
{
    QLine line_trans(x1,y1,x2,y2);
    limits=line_trans;
}

AxLine::AxLine(const QPoint &p1, const QPoint &p2)
{
    QLine line_trans(p1,p2);
    limits=line_trans;
}

AxLine:: ~AxLine()
{
}

QLine AxLine::get_mediatrice()
{
    QPoint pp2;
    int a,b,c;
    QPoint pp1((limits.p1().x()+limits.p2().x())/2,((limits.p1().y()+limits.p2().y())/2));
    pp2.setY(100+pp1.y());
    a=2*(limits.p2().x()-limits.p1().x());
    b=2*(limits.p2().y()-limits.p1().y());
    c=pow(limits.p1().x(),2)+pow(limits.p1().y(),2)-pow(limits.p2().x(),2)-pow(limits.p2().y(),2);
    pp2.setX((-c-b*pp2.y())/a);
    return QLine(pp1,pp2);
}

bool AxLine::is_cw()
{
    return cw;
}

bool AxLine::is_ccw()
{
    return !cw;
}

void AxLine::set_cw(bool way)
{
    if (this->is_cw()!= way)
    {
     limits = QLine(limits.p2(),limits.p1()) ;

    }
    cw = way;

}

void AxLine::set_ccw(bool way)
{
    way = !way;
    if (this->is_cw()!= way)
    {
     limits = QLine(limits.p2(),limits.p1()) ;

    }
    cw = way;

}


AxLine :: AxLine()
{
    QLine line_trans;
    limits=line_trans;
}


QPoint AxLine::middle_point()
{
    return limits.center();
}

void AxLine::affiche(QPaintDevice *device, int width, const QColor &color)
{
    QPainter painter(device);
    QPen pen;
    pen.setWidth(width);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawLine(limits);
}

int AxLine::getObjectType()
{
    //object is line
    return 0;
}

//AxBorder AxLine::getObject()
//{
//    return *this;
//}

bool AxLine::operator!=(const QLine &line_test) const
{
    return(limits!=line_test);
}

bool AxLine::operator==(const AxLine &line_test) const
{
    if (limits.p1()==line_test.p2())
    {
        if (limits.p2()==line_test.p1())
        {
            return true;
        }
    }
    if (limits.p2()==line_test.p2())
    {
        if (limits.p1()==line_test.p1())
        {
            return true;
        }
    }
    return false;

//    return(line==line_test);

}

void AxLine::f(QDebug& dbg) const
{
    dbg.nospace() << "AxLine(" << x1() << "," << y1() << "," << x2() << "," << y2()<< ")"<<endl;
}





QDebug operator<<(QDebug dbg, const AxLine &type)
{
    dbg.nospace() << "AxLine(" << type.x1() << "," << type.y1() << "," << type.x2() << "," << type.y2()<< ")"<<endl;
    return dbg.maybeSpace();
}

