#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"presentateur.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
 void on_pb_ajouter_clicked();

void on_pb_supprimer_clicked();
void on_modifier_clicked();
bool controlSaisie();




void on_ok_clicked();

void on_comboBox_highlighted(const QString &arg1);

void on_up_clicked();

void on_down_clicked();


void on_tab_P_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    presentateur p;
};

#endif // MAINWINDOW_H
