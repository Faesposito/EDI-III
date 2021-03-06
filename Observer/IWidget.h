/**************************************** Widget Interface ***********************************/

#ifndef IWIDGET_H
#define IWIDGET_H

class IWidget
{
public:
    virtual ~IWidget() {}
    virtual void draw() = 0;
};

#endif // IWIDGET_H
