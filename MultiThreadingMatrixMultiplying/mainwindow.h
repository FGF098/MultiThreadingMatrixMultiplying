#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainwindow.h"
#include "matrix_int.h"
#include "int_randomizer.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

    MatrixInt* first_matrix;
    MatrixInt* second_matrix;
    MatrixInt* third_matrix;

    IntRandomizer generator;
};
