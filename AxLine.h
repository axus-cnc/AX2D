#ifndef AXLINE_H
#define AXLINE_H

#include <QLineF>
#include <QPointF>
#include <QStyle>
#include <AxBorder.h>
#include <QDebug>

#include <iostream>
using namespace std;


class AxLine : public AxBorder
{
    public:

        //CONSTRUCTOR

        AxLine(const QLine &line);
        AxLine(AxBorder *border);
        AxLine(QLineF _line);
        AxLine(qreal x1, qreal y1, qreal x2, qreal y2);
        AxLine(const QPointF &p1, const QPointF &p2);
        AxLine();


        //GETTERS

        virtual QLineF get_mediatrice();
        // return 2 points of the mediatrice of the line

        virtual QPointF middle_point();
        // return the middle point between p1 and p2

        virtual int getObjectType();
        // return 0
		
		void set_cw(bool);
        void set_ccw(bool);
        bool is_cw();
        bool is_ccw();


        //Plot

        virtual void affiche(QPaintDevice *device, int width, const QColor &color);
        //graphical plot

        friend QDebug operator<<(QDebug dbg, const AxLine &type);
        virtual void f(QDebug& dbg) const;
        //command plot


        // OTHER

        virtual ~AxLine(); // destructor
        bool operator!=(const QLineF &line) const;
        bool operator==(const AxLine &line) const;


    private:
	
	bool cw;
};

#endif // AXLINE_H