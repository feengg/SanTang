#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H
#include <QPushButton>

class closeButton : public QPushButton
{
public:
    closeButton(QWidget * parent = 0);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

};

#endif // CLOSEBUTTON_H
