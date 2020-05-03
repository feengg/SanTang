#ifndef MINBUTTON_H
#define MINBUTTON_H
#include<QPushButton>

class minButton : public QPushButton
{
public:
    minButton(QWidget * parent = 0);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // MINBUTTON_H
