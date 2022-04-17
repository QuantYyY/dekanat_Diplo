#ifndef DIALOG_1_H
#define DIALOG_1_H

#include <QDialog>
#include "dialog_4.h"


namespace Ui {
class Dialog_1;
}

class Dialog_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_1(QWidget *parent = nullptr);
    ~Dialog_1();

    void set(double d1, double d2, double d3);

    void set(std::vector<double>* tk2, int nlk, float maxsumtk, float topt, float sumtk,
             double tz1, float tk1, float maxnlk, double dsh, double alfash, double ddsh,
             double ci, double fp, double fo, double nu, double hp, double nok, double kk1,
             double v, double no, double di, double lyamda, double hr, double ho, double s,
             double fim, double b, double nz, double nlz, QString motion, std::vector<double>* tz, double scp);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Dialog_1 *ui;
        Dialog_4 d4;
};

#endif // DIALOG_1_H
