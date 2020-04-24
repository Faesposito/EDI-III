/*************************************************************************************************/
/****************************************WIDGET INTERFACE********************************/

#ifndef IWIDGET_H
#define IWIDGET_H

class IWidget
{
public:
    virtual ~IWidget() {}
    virtual void Draw() = 0;
};

#endif // IWIDGET_H
