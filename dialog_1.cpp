#include "dialog_1.h"
#include "ui_dialog_1.h"

Dialog_1::Dialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_1)
{
    ui->setupUi(this);
}

Dialog_1::~Dialog_1()
{
    delete ui;
}

void Dialog_1::set(double d1, double d2, double d3)
{
    ui->label_2->setText("Допустимая максимальная толщина стружки = "+ QString::number(d1));
    ui->label_3->setText("Средняя толщина стружки = "+ QString::number(d2));
    ui->label_4->setText("Средняя оптимальная ширина стружки для забойных резцов = "+ QString::number(d3));
}

void Dialog_1::set(std::vector<double>* tk2, int nlk, float maxsumtk, float topt, float sumtk,
                   double tz1, float tk1, float maxnlk, double dsh, double alfash, double ddsh,
                   double ci, double fp, double fo, double nu, double hp, double nok, double kk1,
                   double v, double no, double di, double lyamda, double hr, double ho, double s,
                   double fim, double b, double nz, double nlz, QString motion, std::vector<double>* tz, double scp)
{
    do{
           for (int ilk = 1; ilk <= nlk && nlk != 0; ilk++)
           {
             float tkbuffer = (((tz1 - tk1)*(ilk - 1))/(nlk -1)) + tk1;
             tk2->push_back(tkbuffer);
             sumtk += tkbuffer;
             ui->textBrowser->setText(ui->textBrowser->toPlainText() + "sumtk = " + QString::number(sumtk) + "\n");
             //std::cout << "sumtk = " << sumtk << std::endl;
           }
           if (sumtk > maxsumtk && (sumtk >= 1.3*topt) && (sumtk <= 2*topt))
           {
             maxsumtk = sumtk;
             maxnlk = nlk;
             ui->label->setText("Необходимое условие для длины кутковой части : \n" + QString::number(1.3*topt) + " <= " +
                                      QString::number(maxsumtk) + " <= " + QString::number(2*topt) + "\n");
             //std::cout << "Необходимое условие для длины кутковой части : " << 1.3*topt << " <= " << maxsumtk << " <= " << 2*topt << std::endl;
             break;
           }
           else {
             tk2->clear();
             sumtk = 0;
             nlk ++;
           }
         }while(true);





    ui->label->setText(ui->label->text() + "Длина кутковой части исполнительного органа = " + QString::number(maxsumtk) + " см,\nпри числе линий резания: " +
                       QString::number(maxnlk));

    ui->label_5->setText("Диаметр шнека = " + QString::number(dsh));
    ui->label_6->setText("Угол подъема винта шнека = " + QString::number(alfash));
    ui->label_7->setText("Диаметр ступицы шнека =" + QString::number(ddsh));
    ui->label_8->setText("Толщина винта шнека =" + QString::number(ci));
    ui->label_9->setText("Приведенная площадь потока угля =" + QString::number(fp));
    ui->label_10->setText("Коэффициент использования сечения шнека =" + QString::number(fo));


    d4.set(tk2, nlk, maxsumtk, topt, sumtk,
           tz1, tk1, maxnlk, dsh, alfash, ddsh,
           ci, fp, fo, nu, hp, nok, kk1,
           v, no, di, lyamda, hr, ho, s,
           fim, b, nz, nlz, motion, tz, scp);
}

void Dialog_1::on_pushButton_clicked()
{
    ui->textBrowser->setText("");
    this->close();
}



void Dialog_1::on_pushButton_2_clicked()
{
    d4.show();
}

