#ifndef AXLINE_H
#define AXLINE_H

#include <QLine>
#include <QPoint>
#include <QStyle>
#include <AxBorder.h>
#include <QDebug>

#include <iostream>
using namespace std;


class AxLine : public AxBorder
{
    public:

        //CONSTRUCTOR

        //AxLine(const QLine &line);
        AxLine(AxBorder *border);
        AxLine(QLine _line, int _kind=0);
        AxLine(int x1, int y1, int x2, int y2, int _kind=0);
        AxLine(const QPoint &p1, const QPoint &p2, int _kind=0);
        AxLine();


        //GETTERS

        virtual QLine get_mediatrice();
        // return 2 points of the mediatrice of the line

        virtual QPoint middle_point();
        // return the middle point between p1 and p2

        virtual int getObjectType();
        // return 0
		
        //void set_cw(bool);
        //void set_ccw(bool);
        //bool is_cw();
        //bool is_ccw();


        int dx();
        int dy();

        virtual void translate(int offset);
        // translate of offset value in offset direction
        // +  = right hand
        // - is left hand

        void translate(int x, int y);

        //Plot

        virtual void display(QPaintDevice *device, int width, const QColor &color);
        //graphical plot

        friend QDebug operator<<(QDebug dbg, const AxLine &type);
        virtual void f(QDebug& dbg) const;
        //command plot


        // OTHER

        virtual ~AxLine(); // destructor
        bool operator!=(const QLine &line) const;
        bool operator==(const AxLine &line) const;


    private:
	
	bool cw;
};

#endif // AXLINE_H
