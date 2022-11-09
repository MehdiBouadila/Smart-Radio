#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include"emission.h"
#include <QModelIndex>
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
    void on_tab_emi_activated(const QModelIndex &index);
    void on_pb_supp_clicked();
    void on_bt_modif_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_comboBox_highlighted(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Emission E;

};

#endif // MAINWINDOW_H
