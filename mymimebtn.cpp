#include "mymimebtn.h"


MyMimeBtn::MyMimeBtn(int r,int c,QLabel * label,QWidget * parent):QPushButton(parent)
{
    row = r;
    col = c;
    mineLabel = label;
    //
    this->setStyleSheet("border-image: url(:/images/mimeGame/cover.png);");
}


void MyMimeBtn::getDoubleClickedSlot()
{
    if(isClicked)
    {
        emit sendDoubleClickedSig(row,col);
    }
}
int MyMimeBtn::getRow()
{
    return row;
}

int MyMimeBtn::getCol()
{
    return col;
}

void MyMimeBtn::enterEvent(QEvent *)
{
    if(isFirstState)
    {
        this->setStyleSheet("border-image: url(:/images/mimeGame/cover-hover.png);");
    }
}

void MyMimeBtn::leaveEvent(QEvent *)
{
    if(isFirstState)
    {
        this->setStyleSheet("border-image: url(:/images/mimeGame/cover.png);");
    }
}
void MyMimeBtn::setIsNotFirstState()
{
    isFirstState = false;
}
bool MyMimeBtn::getIsNotFirstState()
{
    return isFirstState;
}
void MyMimeBtn::setMine()
{
    isMine = true;
}
bool MyMimeBtn::checkIfMine()
{
    return isMine;
}

void MyMimeBtn::setBlankStyle()
{
    this->setStyleSheet("background-color: rgb(221, 245, 255);");
}

void MyMimeBtn::setNumStyle(int mineNum)
{
    switch (mineNum)
    {
    case 0:
        this->setBlankStyle();
        break;
    case 1:
        this->setStyleSheet("color: rgb(0, 0, 255);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("1");
        break;
    case 2:
        this->setStyleSheet("color: rgb(0, 170, 0);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("2");
        break;
    case 3:
        this->setStyleSheet("color: rgb(170, 0, 0);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("3");
        break;
    case 4:
        this->setStyleSheet("color: rgb(0, 0, 127);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("4");
        break;
    case 5:
        this->setStyleSheet("color: rgb(85, 0, 255);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("5");
        break;
    case 6:
        this->setStyleSheet("color: rgb(255, 0, 0);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("6");
        break;
    case 7:
        this->setStyleSheet("color: rgb(255, 149, 96);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("7");
        break;
    case 8:
        this->setStyleSheet("color: rgb(255, 85,0);font: 75 26pt ""Utsaah"";background-color: rgb(221, 245, 255);");
        this->setText("8");
        break;
    default:
        break;
    }
}

void MyMimeBtn::setMineBtnSize(int size)
{
    this->setMinimumSize(size,size);
    this->setMaximumSize(size,size);
}

void MyMimeBtn::mousePressEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::RightButton)
    {
        if(isClicked == false)
        {
            if(isMarked == false)
            {
                this->setStyleSheet("border-image: url(:/images/mimeGame/cover-mark.png);");
                isMarked = true;
                isFirstState = false;
                mineLabel->setText(QString::number(mineLabel->text().toInt()-1));
            }else{
                this->setStyleSheet("border-image: url(:/images/mimeGame/cover.png);");
                isMarked = false;
                isFirstState = true;
                mineLabel->setText(QString::number(mineLabel->text().toInt()+1));
            }
        }
    }
    if(e->buttons() == Qt::LeftButton)
    {
        if(isClicked == false && isMarked == false)
        {
            isClicked = true;
            emit sendPositionSig(row,col);
        }
    }
}

void MyMimeBtn::setMineStyle()
{
    this->setStyleSheet("border-image: url(:/images/mimeGame/mime.png);");
}

void MyMimeBtn::setErrorMineStyle()
{
    this->setStyleSheet("border-image: url(:/images/mimeGame/mime-error.png);");
}
void MyMimeBtn::setMarkedMineStyle()
{
    this->setStyleSheet("border-image: url(:/images/mimeGame/mine-mark.png);");
}

void MyMimeBtn::setAroundMinesNum(int num)
{
    aroundMinesNum = num;
}

int MyMimeBtn::getAroundMinesNum()
{
    return aroundMinesNum;
}

bool MyMimeBtn::getClickState()
{
    return isClicked;
}

bool MyMimeBtn::isBlankChecked()
{
    return blankCheckedState;
}

void MyMimeBtn::setBlankChecked()
{
    blankCheckedState = true;
}
bool MyMimeBtn::getMarkState()
{
    return isMarked;
}
void MyMimeBtn::setClicked()
{
    isClicked = true;
}
void MyMimeBtn::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        if(isClicked)
        {
            emit sendDoubleClickedSig(row,col);
        }
    }
}
