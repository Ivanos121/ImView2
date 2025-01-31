#include "spinboxdelegate.h"

#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget* SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
    // editor->setFrame(false);
    // editor->setMinimum(0);
    // editor->setMaximum(100);
    editor->setRange(-100.0, 100.0);
    editor->setSingleStep(0.1);
    editor->setDecimals(3);

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}
