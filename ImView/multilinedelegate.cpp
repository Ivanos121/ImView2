#include "multilinedelegate.h"
#include <QPlainTextEdit>

QWidget *MultilineDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return new QPlainTextEdit(parent);
}

void MultilineDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (auto *textEdit = qobject_cast<QPlainTextEdit *>(editor)) {
        textEdit->setPlainText(index.data(Qt::EditRole).toString());
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void MultilineDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (auto *textEdit = qobject_cast<QPlainTextEdit *>(editor)) {
        model->setData(index, textEdit->toPlainText());
    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}
