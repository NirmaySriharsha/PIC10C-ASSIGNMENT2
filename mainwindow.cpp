#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_9->setVisible(true);
    ui->label_14->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compute_grade_pic10b() const{
    std::vector<int> homework_scores;
    homework_scores.push_back(ui->horizontalSlider->value());
    homework_scores.push_back(ui->horizontalSlider_2->value());
    homework_scores.push_back(ui->horizontalSlider_3->value());
    homework_scores.push_back(ui->horizontalSlider_4->value());
    homework_scores.push_back(ui->horizontalSlider_5->value());
    homework_scores.push_back(ui->horizontalSlider_6->value());
    homework_scores.push_back(ui->horizontalSlider_7->value());
    homework_scores.push_back(ui->horizontalSlider_11->value());
    int min_pos=0;
    for (int i=0; i<homework_scores.size();i++)
    {
        if(homework_scores[i]<homework_scores[min_pos])
            min_pos=i;
    }
    homework_scores[min_pos]=homework_scores[homework_scores.size()-1];
    homework_scores.pop_back();
    double average=0;
    for (int i=0; i<homework_scores.size();i++)
        average+=homework_scores[i];
    average/=homework_scores.size();
    double midterm_1=ui->horizontalSlider_8->value();
    double midterm_2=ui->horizontalSlider_9->value();
    double final=ui->horizontalSlider_10->value();
    double better_midterm=midterm_1;
    if(midterm_2>midterm_1)
        better_midterm=midterm_2;
    double scheme_a= (0.25*average)+(0.2*(midterm_1+midterm_2))+(0.35*final);
    double scheme_b=(0.25*average)+(0.3*better_midterm)+(0.44*final);
    bool a=ui->radioButton->isChecked();
    bool b=ui->radioButton_2->isChecked();
    if (a)
        emit emit_final_grade(QString::number(scheme_a));
    else if(b)
        emit emit_final_grade(QString::number(scheme_b));
    else
        {if(scheme_a>scheme_b)
            emit emit_final_grade(QString::number(scheme_a));
        else
            emit emit_final_grade(QString::number(scheme_b));
        }
}
void MainWindow::compute_grade_pic10c() const{
    std::vector<int> homework_scores;
    homework_scores.push_back(ui->horizontalSlider->value());
    homework_scores.push_back(ui->horizontalSlider_2->value());
    homework_scores.push_back(ui->horizontalSlider_3->value());
    double average=0;
    for (int i=0; i<homework_scores.size();i++)
        average+=homework_scores[i];
    average/=homework_scores.size();
    double midterm=ui->horizontalSlider_8->value();
    double final_project=ui->horizontalSlider_9->value();
    double final=ui->horizontalSlider_10->value();
    double scheme_a= (0.15*average)+(0.25*midterm)+(0.3*final)+(0.35*final_project);
    double scheme_b= (0.15*average)+(0.5*final)+(0.35*final_project);
    bool a=ui->radioButton->isChecked();
    bool b=ui->radioButton_2->isChecked();
    if(a)
        emit emit_final_grade(QString::number(scheme_a));
    else if (b)
        emit emit_final_grade(QString::number(scheme_b));
    else
    {
        if(scheme_a>scheme_b)
            emit emit_final_grade(QString::number(scheme_a));
        else
            emit emit_final_grade(QString::number(scheme_b));
    }

}

void MainWindow::slot_change_class(int course) const{
    bool show;
    switch(course){
    case 0:
        show=true;
        break;
    case 1:
        show=false;
        break;
    default:
        show=true;
        break;
    }
    ui->horizontalSlider_4->setEnabled(show);
    ui->horizontalSlider_4->setValue(0);

    ui->horizontalSlider_5->setEnabled(show);
    ui->horizontalSlider_5->setValue(0);

    ui->horizontalSlider_6->setEnabled(show);
    ui->horizontalSlider_6->setValue(0);

    ui->horizontalSlider_7->setEnabled(show);
    ui->horizontalSlider_7->setValue(0);

    ui->horizontalSlider_11->setEnabled(show);
    ui->horizontalSlider_11->setValue(0);

    ui->horizontalSlider_8->setValue(0);
    ui->horizontalSlider_9->setValue(0);
    ui->horizontalSlider_10->setValue(0);


    ui->spinBox_4->setEnabled(show);
    ui->spinBox_5->setEnabled(show);
    ui->spinBox_6->setEnabled(show);
    ui->spinBox_7->setEnabled(show);
    ui->spinBox_11->setEnabled(show);

    ui->label_4->setEnabled(show);
    ui->label_5->setEnabled(show);
    ui->label_6->setEnabled(show);
    ui->label_7->setEnabled(show);
    ui->label_12->setEnabled(show);


    //ui->label_9->setEnabled(show);
    //ui->label_14->setEnabled(!show);
    ui->label_9->setVisible(show);
    ui->label_14->setVisible(!show);

}

void MainWindow::slot_compute() const{
    int course = ui->comboBox->currentIndex();
    if (course == 0)
        compute_grade_pic10b();
    else
        compute_grade_pic10c();
}
