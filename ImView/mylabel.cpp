#include "mylabel.h"

#include <QDesktopServices>

MyLabel::MyLabel(const QString &text, QWidget *parent) : QLabel(parent)
{
    setTextFormat(Qt::RichText);
    setText(text);
    setOpenExternalLinks(true);
    setFrameStyle(QFrame::NoFrame); // Убираем рамку
    setStyleSheet("border: none;");
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    setFrameStyle(QFrame::NoFrame);  // Убираем рамку при клике
    setStyleSheet("border: none;");  // Убираем стиль рамки

    if (event->button() == Qt::LeftButton) {
        // Здесь можно вызвать внешний URL, если необходимо
        QDesktopServices::openUrl(QUrl("http://example.com")); // Замените на вашу ссылку
    }

    QLabel::mousePressEvent(event);   // Вызов базового метода
}
