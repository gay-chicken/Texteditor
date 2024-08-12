#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QTextEdit>

class TextArea : public QTextEdit
{
public:
    TextArea(QWidget *parent);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    bool isControl = false;
};

#endif // TEXTAREA_H
