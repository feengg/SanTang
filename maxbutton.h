#ifndef MAXBUTTON_H
#define MAXBUTTON_H
#include <QPushButton>

class maxButton : public QPushButton
{
public:
    maxButton(QWidget * parent = 0);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // MAXBUTTON_H
