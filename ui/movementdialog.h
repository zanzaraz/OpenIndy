#ifndef MOVEMENTDIALOG_H
#define MOVEMENTDIALOG_H

#include <QDialog>
#include <QDebug>
#include "configuration.h"
#include "reading.h"
#include "unitconverter.h"

namespace Ui {
class MovementDialog;
}

class MovementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MovementDialog(QWidget *parent = 0);
    ~MovementDialog();

signals:
    void sendReading(Reading*);

private slots:
    void on_pushButton_move_clicked();
    void initGUI();

    void on_comboBox_typeOfReading_currentIndexChanged(const QString &arg1);

private:
    Ui::MovementDialog *ui;

    Configuration::ReadingTypes typeOfReading;
};

#endif // MOVEMENTDIALOG_H
