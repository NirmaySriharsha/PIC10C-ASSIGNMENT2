#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void compute_grade_pic10b() const;
    void compute_grade_pic10c() const;
private slots:
    void slot_compute() const;
    void slot_change_class(int) const;
signals:
    void emit_final_grade(QString) const;
};

#endif // MAINWINDOW_H
