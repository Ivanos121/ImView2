#include <QTextEdit>

//#include "delegate.h"
#include <qpainter.h>
#include <QStyleOptionViewItem>
#include "resizedelegate.h"

TextEditDelegate::TextEditDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *TextEditDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QTextEdit *editor = new QTextEdit(parent);

    return editor;
}

void TextEditDelegate::drawDisplay(QPainter *painter, const QStyleOptionViewItem &option,
                                   const QRect &rect, const QString &text) const
{
    QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                              ? QPalette::Normal : QPalette::Disabled;
    if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
        cg = QPalette::Inactive;
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(rect, option.palette.brush(cg, QPalette::Highlight));
        painter->setPen(option.palette.color(cg, QPalette::HighlightedText));
    } else {
        painter->setPen(option.palette.color(cg, QPalette::Text));
    }

    if (text.isEmpty())
        return;

    if (option.state & QStyle::State_Editing) {
        painter->save();
        painter->setPen(option.palette.color(cg, QPalette::Text));
        painter->drawRect(rect.adjusted(0, 0, -1, -1));
        painter->restore();
    }
    QTextOption opt(option.displayAlignment);
    opt.setWrapMode(QTextOption::WordWrap);
    painter->save();
    if (option.state & QStyle::State_Selected) {
        painter->setPen(option.palette.color(cg, QPalette::HighlightedText));
    }
    else {
        painter->setPen(option.palette.color(cg, QPalette::Text));
    }
    painter->drawText(rect.adjusted(1, 0, 0, 0), text, opt);
    painter->restore();
}
