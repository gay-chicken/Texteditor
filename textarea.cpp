#include "textarea.h"

#include <QWheelEvent>

TextArea::TextArea(QWidget *parent) : QTextEdit(parent)
{

}

void TextArea::wheelEvent(QWheelEvent *event)
{
    if (!isControl) {
        QTextEdit::wheelEvent(event);
        return;
    }

    if (event->angleDelta().y() > 0) {
        zoomIn();
    } else if (event->angleDelta().y() < 0) {
        zoomOut();
    }
    event->accept();
}

void TextArea::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        isControl = true;
    }
    QTextEdit::keyPressEvent(event);
}

void TextArea::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        isControl = false;
    }
    QTextEdit::keyPressEvent(event);
}
